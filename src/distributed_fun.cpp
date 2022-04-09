#include "distributed_fun.h"
#include "mywidget.h"
#include "distributed_waitpage.h"
DistributedFun::DistributedFun(QObject *parent)
{
    m_flag1 = 0;
    m_flag2 = 0;
    m_flag3 = 0;
    m_flag4 = 0;
}
DistributedFun::~DistributedFun()
{
    qDebug()<<"关闭成功";
    //openFlag = !openFlag;
}
void DistributedFun::show_page(QWidget* wtr)
{
    flag_queue.push_back(&flag1);
    flag_queue.push_back(&flag2);
    flag_queue.push_back(&flag3);
    flag_queue.push_back(&flag4);
    lbtn = new QPushButton;     //设置令牌按钮
    QPalette pa(lbtn->palette());            //设置画盘
    pa.setColor(QPalette::Button,Qt::yellow);//QColor(255,0,0)
    lbtn->setAutoFillBackground(true);      //用来填充背景的必备函数
    lbtn->setFlat(true);
    lbtn->setParent(wtr);
    lbtn->resize(50,50);
    lbtn->setText("令牌");
    lbtn->setPalette(pa);
    QTimer* timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &DistributedFun::update_lbtn); //信号发送者timer,信号发出的时间timeout,信号接受者wtr窗口,槽函数
    int move_x[4] = {350, 700, 350, 100};
    int move_y[4] = {0, 350, 700, 350};
    for(int i = 0;i <= 3;i++)
    {
        num[i]->setParent(wtr);
        num[i]->resize(100,100);
        num[i]->move(move_x[i],move_y[i]);
        num[i]->setText("程序"+QString::number(i+1));//需注意必须使用QString
        num[i]->show();
    }
    timer->start(1000);
}
void DistributedFun :: update_lbtn() //每一次超时就调用该槽函数，该函数将重新定义按钮的方位
{
    lbtn->close();                            //每次调用该函数先将原按钮关闭
    qDebug()<<"Enter timeout processing function\n";
    int* ptr = (int*)flag_queue.head();
    *ptr = !*ptr;               //将队列的第一个元素置反
    flag_queue.push_back(ptr);  //将第一个元素压入队列的末尾
    flag_queue.pop_front();                   //将队列的第一个元素弹出
    if(flag1)
    {
        lbtn->move(380, 100);
        lbtn->show();
        flag1 = !flag1;
        if(m_flag1)
        {
            //btn1->close();
            QPalette pa(btn1->palette());         //设置画盘
            pa.setColor(QPalette::Button,Qt::red);//QColor(255,0,0)
            btn1->setAutoFillBackground(true);    //用来填充背景的必备函数
            btn1->setFlat(true);                  //也必备
            btn1->setText("<程序1>正在执行...");
            btn1->setPalette(pa);
            btn1->show();
        }
    }
    else if(flag2)
    {
         lbtn->move(650, 380);
         lbtn->show();
         flag2 = !flag2;
         if(m_flag2)
         {
             QPalette pa(btn2->palette());         //设置画盘
             pa.setColor(QPalette::Button,Qt::red);//QColor(255,0,0)
             btn2->setAutoFillBackground(true);    //用来填充背景的必备函数
             btn2->setFlat(true);                  //也必备
             btn2->setText("<程序2>正在执行...");
             btn2->setPalette(pa);
             btn2->show();
         }
    }
    else if(flag3)
    {
        lbtn->move(380, 650);
        lbtn->show();
        flag3 = !flag3;
        if(m_flag3)
        {
            QPalette pa(btn3->palette());         //设置画盘
            pa.setColor(QPalette::Button,Qt::red);//QColor(255,0,0)
            btn3->setAutoFillBackground(true);    //用来填充背景的必备函数
            btn3->setFlat(true);                  //也必备
            btn3->setText("<程序3>正在执行...");
            btn3->setPalette(pa);
            btn3->show();
        }
    }
    else if(flag4)
    {
        lbtn->move(200, 380);
        lbtn->show();
        flag4 = !flag4;
        if(m_flag4)
        {
            QPalette pa(btn4->palette());         //设置画盘
            pa.setColor(QPalette::Button,Qt::red);//QColor(255,0,0)
            btn4->setAutoFillBackground(true);    //用来填充背景的必备函数
            btn4->setFlat(true);                  //也必备
            btn4->setText("<程序4>正在执行...");
            btn4->setPalette(pa);
            btn4->show();
        }
    }
}
//_________________________________________
void DistributedFun::show_waitpage()
{
    QWidget* wtr = new QWidget;
    wtr->setWindowTitle("WaitApplication");
    wtr->setFixedSize(400,100);
    for(int i = 0;i<4;i++)
    {
        wbtn_num[i]->setParent(wtr);
        wbtn_num[i]->resize(100,100);
        wbtn_num[i]->setText("程序"+QString::number(i+1));
        wbtn_num[i]->move(i*100,0);
    }
    wtr->setWindowModality(Qt::ApplicationModal);//设置模态窗口
    //连接wait按键与更新m_flag事件
    connect(wbtn1, &QPushButton::clicked, this, &DistributedFun::update_wbtn1);
    connect(wbtn2, &QPushButton::clicked, this, &DistributedFun::update_wbtn2);
    connect(wbtn3, &QPushButton::clicked, this, &DistributedFun::update_wbtn3);
    connect(wbtn4, &QPushButton::clicked, this, &DistributedFun::update_wbtn4);
    wtr->show();
}
void DistributedFun::update_wbtn1()
{
    QPalette pa(wbtn1->palette());            //设置画盘
    pa.setColor(QPalette::Button,Qt::green);//QColor(255,0,0)
    wbtn1->setAutoFillBackground(true);      //用来填充背景的必备函数
    wbtn1->setFlat(true);                    //也必备
    wbtn1->setPalette(pa);
    wbtn1->setText("程序1申请");
    wbtn1->show();
    m_flag1 = !m_flag1;
}
void DistributedFun::update_wbtn2()
{
    QPalette pa(wbtn2->palette());            //设置画盘
    pa.setColor(QPalette::Button,Qt::green);//QColor(255,0,0)
    wbtn2->setAutoFillBackground(true);      //用来填充背景的必备函数
    wbtn2->setFlat(true);                    //也必备
    wbtn2->setPalette(pa);
    wbtn2->setText("程序2申请");
    wbtn2->show();
    m_flag2 = !m_flag2;
}
void DistributedFun::update_wbtn3()
{
    QPalette pa(wbtn1->palette());            //设置画盘
    pa.setColor(QPalette::Button,Qt::green);//QColor(255,0,0)
    wbtn3->setAutoFillBackground(true);      //用来填充背景的必备函数
    wbtn3->setFlat(true);                    //也必备
    wbtn3->setPalette(pa);
    wbtn3->setText("程序3申请");
    wbtn3->show();
    m_flag3 = !m_flag3;
}
void DistributedFun::update_wbtn4()
{
    QPalette pa(wbtn4->palette());            //设置画盘
    pa.setColor(QPalette::Button,Qt::green);//QColor(255,0,0)
    wbtn4->setAutoFillBackground(true);      //用来填充背景的必备函数
    wbtn4->setFlat(true);                    //也必备
    wbtn4->setPalette(pa);
    wbtn4->setText("程序4申请");
    wbtn4->show();
    m_flag4 = !m_flag4;
}
//void Distributed_waitpage::closeEvent(QCloseEvent* event)
//{
//    event->ignore();
//}

int DistributedFun::get_mflag1()
{
    return m_flag1;
}
int DistributedFun::get_mflag2()
{
    return m_flag2;
}
int DistributedFun::get_mflag3()
{
    return m_flag3;
}
int DistributedFun::get_mflag4()
{
    return m_flag4;
}



