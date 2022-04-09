#include "centration_fun.h"
CentrationFun::CentrationFun(QObject *parent)
{
    m_flag1 = 0;
    m_flag2 = 0;
    m_flag3 = 0;
    m_flag4 = 0;
    count = 0;
}
CentrationFun::~CentrationFun()
{
    qDebug()<<"关闭成功";
}
void CentrationFun::show_page(QWidget* wtr)
{
    SetQueueLabel(wtr);
    //——————————设置队头按键——————————
    QPushButton* Tbtn = new QPushButton;
    Tbtn->setParent(wtr);
    Tbtn->setText("队头");
    QPalette pa(Tbtn->palette());         //设置画盘
    pa.setColor(QPalette::Button,Qt::gray);//QColor(255,0,0)
    Tbtn->setAutoFillBackground(true);    //用来填充背景的必备函数
    Tbtn->setFlat(true);                  //也必备
    Tbtn->setPalette(pa);
    Tbtn->resize(50,100);
    Tbtn->move(0,50);
    Tbtn->show();
    //———————————————————————————————
    for(int i = 0; i <= 3; i++)
    {
        btn_num[i]->setParent(wtr);
        btn_num[i]->setText("程序"+QString::number(i+1));//需注意必须使用QString
    }
    QTimer* Ctimer = new QTimer(this);
    connect(Ctimer, &QTimer::timeout, this, &CentrationFun::update_queue);
    Ctimer->start(1500);
    QTimer* C2timer = new QTimer(this);
    connect(C2timer, &QTimer::timeout, this, &CentrationFun::ExamWait);
    C2timer->start(900);
}
void CentrationFun::update_queue()
{
  int x = IsExist();
  if(x != -1) //如果不是重复项则进入
  {
    if(BtnQueue.size() <= 4)   //如果队列不超过4
    {
        qDebug()<<"The BtnQueue is updating!";
        BtnQueue.push_back(btn_num[x]);
        qDebug()<<x;
        ShowBtn(x);
    }
    else
    {
        qDebug()<<"队列已满！";
    }
  }
  else
  {
      qDebug()<<"出现重复项！";
  }
}
int CentrationFun::IsExist()
{
    int x = rand() % 4;
    if(WaitNum.size() != 4)
    {
        for(int i = 0; i < WaitNum.size(); i++)  //遍历整个数组查找是有重复项
        {
            if(x == WaitNum[i])
            {
                return -1;
            }
        }
        WaitNum.push_back(x);
        return x;
    }
    else
    {
        int temp = WaitNum.back();
        if(temp == x)
            return -1;
        WaitNum.clear();
        return x;
    }
}
void CentrationFun::ExamWait()
{
    qDebug()<<"ExamWait!";
    if(BtnQueue.size() > 1)
    {
        count = 0;

        BtnQueue.front()->close();
        BtnQueue.pop_front();
        int BtnSize = BtnQueue.size();
        for(int i = 0; i < BtnSize; i++)   //如果当前Btnqueue只有一个元素时会产生Bug.
        {
            qDebug()<<"当前："<<i;
            BtnQueue.front()->close();
            BtnQueue.front()->resize(100,100);
            BtnQueue.front()->move(move_x[i%4],50);
            qDebug()<<"ExamWait move_x: "<<move_x[i%4]<<" i: "<<i;
            BtnQueue.front()->show();
            BtnQueue.push_back(BtnQueue.front());
            BtnQueue.pop_front();
        }
    }
}
void CentrationFun::ShowBtn(int x)
{
       int BtnSize = BtnQueue.size();
       for(int i = 0; i < BtnSize; i++) //遍历整个BtnQueue
       {
           qDebug()<<"i= "<<i<<" count= "<<count;
           if(i == 0 && count == 0)//count为0代表该程序排在队列的队首
           {
               QPalette pa(BtnQueue.front()->palette());           //设置画盘
               pa.setColor(QPalette::Button,Qt::yellow);
               //QColor(255,0,0)
               BtnQueue.front()->setAutoFillBackground(true);      //用来填充背景的必备函数
               BtnQueue.front()->setFlat(true);                    //也必备
               //BtnQueue.front()->setText("程序"+QString::number(x+1)+"执行中...");
               BtnQueue.front()->resize(100,100);
               BtnQueue.front()->move(move_x[i%4],50);
               qDebug()<<"first move_x: "<<move_x[i%4]<<" i: "<<i;
               BtnQueue.front()->setPalette(pa);
               BtnQueue.front()->show();
               BtnQueue.push_back(BtnQueue.front());
               BtnQueue.pop_front();
               count++;
           }
           else
           {
               QPalette pa(BtnQueue.front()->palette());           //设置画盘
               pa.setColor(QPalette::Button,Qt::white);
               BtnQueue.front()->setAutoFillBackground(true);      //用来填充背景的必备函数
               BtnQueue.front()->setFlat(true);                    //也必备
               BtnQueue.front()->resize(100,100);
               BtnQueue.front()->setPalette(pa);
               BtnQueue.front()->move(move_x[i%4],50);
               qDebug()<<"back move_x: "<<move_x[i%4]<<" i: "<<i;
               BtnQueue.front()->show();
               BtnQueue.push_back(BtnQueue.front());
               BtnQueue.pop_front();
           }
       }
}
void SetQueueLabel(QWidget* ptr)
{
    QFont ft;               //设置字体
    QPalette pa;            //设置画盘
    ft.setPointSize(15);
    pa.setColor(QPalette::WindowText,Qt::blue);
    QLabel *Qlab = new QLabel;
    Qlab->setParent(ptr);
    Qlab->setText("协调者队列");
    Qlab->setFont(ft);
    Qlab->setPalette(pa);
    Qlab->resize(100,50);
    Qlab->move(150,0);
    Qlab->show();
}
