#include "drawerwidget.h"
#include "ui_drawerwidget.h"

#include<QPropertyAnimation>
#include<QStyle>

DrawerWidget::DrawerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DrawerWidget)
{
    ui->setupUi(this);

    //init
    m_isOpening = true;
    m_label = new QLabel("-");
    QHBoxLayout* titleLayout = new QHBoxLayout();
    ui->pushButton->setLayout(titleLayout);
    titleLayout->addStretch();
    titleLayout->addWidget(m_label);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onToggle()));
}

DrawerWidget::~DrawerWidget()
{
    delete ui;
}

void DrawerWidget::setTitle(const QString &title)
{
    ui->pushButton->setText(title);
}

void DrawerWidget::addWidget(QWidget *widget)
{
}


void DrawerWidget::onToggle()
{
    QPropertyAnimation* anim =new QPropertyAnimation(this,"geometry");
    anim->setDuration(200);
    if(m_isOpening){
        ui->widget->hide();
        m_label->setText("+");
//        m_label->setPixmap(style()->standardPixmap(QStyle::SP_ArrowDown));
        m_height = this->height();
        anim->setStartValue(geometry());
        anim->setEndValue(QRect(geometry().x(),geometry().y(),width(),ui->pushButton->height()));
    }
    else{
        ui->widget->show();
        m_label->setText("-");
//        m_label->setPixmap(style()->standardPixmap(QStyle::SP_ArrowUp));
        anim->setStartValue(geometry());
        anim->setEndValue(QRect(geometry().x(),geometry().y(),width(),m_height));
    }
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    m_isOpening = !m_isOpening;
}
