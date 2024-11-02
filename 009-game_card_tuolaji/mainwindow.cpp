#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QAbstractButton::clicked,this,&MainWindow::onDealCard);
    connect(ui->pushButton_sim,&QAbstractButton::clicked,this,&MainWindow::onSimulation);
    connect(ui->pushButton_simAuto,&QAbstractButton::clicked,this,&MainWindow::onAutoRun);
    connect(&timer,&QTimer::timeout,this,&MainWindow::onSimulation);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onDealCard()
{
    timer.stop();
    player1.clear();
    player2.clear();
    zone.clear();

    // 初始化一副牌
    std::vector<Card> deck;
    for (Suit suit : {HEARTS, DIAMONDS, CLUBS, SPADES}) {
        for (Rank rank : {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE}) {
            deck.push_back({suitToString(suit), rankToString(rank)});
        }
    }

    // 随机洗牌
    std::srand(std::time(nullptr));
    std::random_shuffle(deck.begin(), deck.end());

    // 发牌给两个玩家
    for (size_t i = 0; i < deck.size(); i++) {
        if (i % 2 == 0) {
            player1.push_back(deck[i]);
        } else {
            player2.push_back(deck[i]);
        }
    }

    //刷新
    render();
}

void MainWindow::onSimulation()
{
    if(flag){
        flag = simulate(player1);
    }
    else{
        flag = !simulate(player2);
    }
}

void MainWindow::onAutoRun()
{
    if(!isRunning){
        timer.start(50);
        ui->pushButton_sim->setEnabled(false);
        isRunning = true;
    }
    else{
        timer.stop();
        ui->pushButton_sim->setEnabled(true);
        isRunning = false;
    }
}

bool MainWindow::simulate(std::list<Card> &player)
{
    if(player.empty()){
        QMessageBox::information(this,"Game Finish","Game Finish");
        timer.stop();
        return false;
    }

    //出牌
    Card card = player.front();
    player.pop_front();
    zone.push_back(card);

    //判定
    bool winCards = false;
    int index = findPosition(card.rank);
    if(index != -1){
        winCards = true;
        auto it = zone.begin();
        // 将迭代器移动到相同点数元素上
        std::advance(it, index);
        // 将元素从zone移动到player的末尾
        player.splice(player.end(), zone, it, zone.end());
    }

    //刷新
    render();

    //
    return winCards;
}

int MainWindow::findPosition(const std::string& rank)
{
    //找到已有的牌中与rank相同的牌的位置
    int indexOfRank = -1;

    size_t i = 0;
    for (Card card  : zone) {
        if(card.rank == rank && i < (zone.size()- 1)){
            indexOfRank = i;
            break;
        }
        i++;
    }

    return indexOfRank;
}


void MainWindow::render()
{
    //玩家A
    std::string txtA = "PlayerA:\n";
    for (const Card& card : player1) {
        txtA.append(card.suit);
        txtA.append(card.rank);
        txtA.append("\n");
    }
    ui->label_playerA->setText(QString::fromStdString(txtA));

    //玩家B
    std::string txtB = "PlayerB:\n";
    for (const Card& card : player2) {
        txtB.append(card.suit);
        txtB.append(card.rank);
        txtB.append("\n");
    }
    ui->label_playerB->setText(QString::fromStdString(txtB));

    //牌区
    std::string txtZone = "Card Zone:\n";
    for (const Card& card : zone) {
        txtZone.append(card.suit);
        txtZone.append(card.rank);
        txtZone.append("\n");
    }
    ui->label_zone->setText(QString::fromStdString(txtZone));
}



// 将枚举转换为字符串
std::string MainWindow::suitToString(Suit suit) {
    switch (suit) {
    case HEARTS: return "♥";
    case DIAMONDS: return "♦";
    case CLUBS: return "♣";
    case SPADES: return "♠";
    default: return "???";
    }
}

std::string MainWindow::rankToString(Rank rank) {
    switch (rank) {
    case ACE: return "A";
    case TWO: return "2";
    case THREE: return "3";
    case FOUR: return "4";
    case FIVE: return "5";
    case SIX: return "6";
    case SEVEN: return "7";
    case EIGHT: return "8";
    case NINE: return "9";
    case TEN: return "10";
    case JACK: return "J";
    case QUEEN: return "Q";
    case KING: return "K";
    default: return "Unknown";
    }
}


