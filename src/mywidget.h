#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <string>
#include <QString>
#include <QDebug>
#include "new_menu.h"
using namespace std;
class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};
void main_label(myWidget* ptr);         //标签函数
 //设置Button的函数,分别传入myWidget的this指针，需要按键显示的字符串str,按键的长rsize_x,宽rsize_y;按键的初始位置横坐标move_x和纵坐标move_y。
QPushButton* set_btn(myWidget* ptr, QString str, int rsize_x, int rsize_y, int move_x, int move_y);


#endif // MYWIDGET_H
