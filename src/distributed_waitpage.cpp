#include "distributed_waitpage.h"

Distributed_waitpage::Distributed_waitpage(QObject *parent)
{
    m_flag1 = 0;
    m_flag2 = 0;
    m_flag3 = 0;
    m_flag4 = 0;
}

void Distributed_waitpage::show_waitpage()
{
    QWidget* wtr = new QWidget;
    wtr->setWindowTitle("WaitApplication");
    wtr->setFixedSize(400,100);
    QPushButton* wbtn1 = new QPushButton;
    QPushButton* wbtn2 = new QPushButton;
    QPushButton* wbtn3 = new QPushButton;
    QPushButton* wbtn4 = new QPushButton;
    wbtn1->setParent(wtr);
    wbtn2->setParent(wtr);
    wbtn3->setParent(wtr);
    wbtn4->setParent(wtr);
    wbtn1->resize(100,100);
    wbtn2->resize(100,100);
    wbtn3->resize(100,100);
    wbtn4->resize(100,100);
    wbtn1->setText("程序1");
    wbtn2->setText("程序2");
    wbtn3->setText("程序3");
    wbtn4->setText("程序4");
    wbtn1->move(0,0);
    wbtn2->move(100,0);
    wbtn3->move(200,0);
    wbtn4->move(300,0);
    wtr->setWindowModality(Qt::ApplicationModal);//设置模态窗口
    //连接wait按键与更新m_flag事件
    connect(wbtn1, &QPushButton::clicked, this, &Distributed_waitpage::update_wbtn1);
    connect(wbtn2, &QPushButton::clicked, this, &Distributed_waitpage::update_wbtn2);
    connect(wbtn3, &QPushButton::clicked, this, &Distributed_waitpage::update_wbtn3);
    connect(wbtn4, &QPushButton::clicked, this, &Distributed_waitpage::update_wbtn4);
    wtr->show();
}
void Distributed_waitpage::update_wbtn1()
{
   // QPushButton* wbtn1 = new QPushButton;

    m_flag1 = !m_flag1;
}
void Distributed_waitpage::update_wbtn2()
{
    m_flag2 = !m_flag2;
}
void Distributed_waitpage::update_wbtn3()
{
    m_flag3 = !m_flag3;
}
void Distributed_waitpage::update_wbtn4()
{
    m_flag4 = !m_flag4;
}
//void Distributed_waitpage::closeEvent(QCloseEvent* event)
//{
//    event->ignore();
//}
int Distributed_waitpage::isOpen()
{
    return openFlag;
}
int Distributed_waitpage::get_mflag1()
{
    return m_flag1;
}
int Distributed_waitpage::get_mflag2()
{
    return m_flag2;
}
int Distributed_waitpage::get_mflag3()
{
    return m_flag3;
}
int Distributed_waitpage::get_mflag4()
{
    return m_flag4;
}

Distributed_waitpage::~Distributed_waitpage()
{
    qDebug()<<"关闭成功";
    openFlag = !openFlag;
}
