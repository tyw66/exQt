#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

// 定义扑克牌的结构体
struct Card {
    std::string suit;  // 花色
    std::string rank;  // 点数
};

// 定义花色和点数的枚举
enum Suit {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

enum Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDealCard();
    void onSimulation();
    void onAutoRun();

private:
    bool simulate(std::list<Card>& player);
    int findPosition(const std::string &rank);
    void render();

    std::string suitToString(Suit suit);
    std::string rankToString(Rank rank);

private:
    Ui::MainWindow *ui;

    std::list<Card> player1, player2, zone;

    bool flag = true; // 应该A出牌

    QTimer timer;
    bool isRunning = false; // 是否正在自动运行
};
#endif // MAINWINDOW_H
