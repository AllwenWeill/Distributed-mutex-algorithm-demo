#include "mywidget.h"
void main_label(myWidget* ptr)
{
    QFont ft;               //设置字体
    QPalette pa;            //设置画盘
    ft.setPointSize(20);
    pa.setColor(QPalette::WindowText,Qt::blue);
    QLabel *lab = new QLabel;
    lab->setParent(ptr);
    lab->setText("Distributed System demo");
    lab->setFont(ft);
    lab->setPalette(pa);
    lab->resize(500,100);
    lab->move(150,0);
    lab->show();
}
QPushButton* set_btn(myWidget* ptr, QString str, int rsize_x, int rsize_y, int move_x, int move_y)
{
    QPushButton *btn = new QPushButton;
    btn->setParent(ptr);                    //将btn对象成为myWidget的子类，从而依附于myWidget窗口
    btn->setText(str);
    btn->resize(rsize_x,rsize_y);                 //设置按键1的固定大小
    btn->move(move_x,move_y);
    btn->show();                          //show以顶层方式弹出窗口控件
    return btn;
}

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //可分成函数块，传入this指针和字体大小等参数
    New_menu *ntr = new New_menu;
    main_label(this);
    connect(set_btn(this,"1.集中式互斥demo",300,200,0,100), &QPushButton::clicked, ntr, &New_menu::show_centration);
    connect(set_btn(this,"2.分布式令牌选举互斥demo",300,200,300,100), &QPushButton::clicked, ntr, &New_menu::show_disturbted);
    connect(set_btn(this,"About Designer",600,50,0,300), &QPushButton::clicked, ntr, &New_menu::show_designer);
    resize(600,350);                      //重置窗口大小
    setFixedSize(600,350);                //设置固定窗口大小，无法更改
    setWindowTitle("Distributed System Demo v1.1");//设置窗口标题
}

myWidget::~myWidget()
{
    qDebug() << "内存已全部释放";
}
