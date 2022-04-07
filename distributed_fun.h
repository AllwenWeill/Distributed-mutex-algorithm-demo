#ifndef DISTRIBUTED_FUN_H
#define DISTRIBUTED_FUN_H
#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <string>
#include <QString>
#include <QDebug>
#include <QQueue>
#include <QTimer>
#include "lbtn.h"
#include "distributed_waitpage.h"
class DistributedFun:public QObject{
    Q_OBJECT
public:
    explicit DistributedFun(QObject *parent = nullptr);
    ~DistributedFun();
    void update();
    void show_waitpage();
    int flag1;
    int flag2;
    int flag3;
    int flag4;
    QQueue<void*> flag_queue;    //此处需注意：应将flag的地址传入进去，否则flagx的改变不会影响到flag_queue队列
    QPushButton* lbtn;
    QPushButton* btn1 = new QPushButton;
    QPushButton* btn2 = new QPushButton;
    QPushButton* btn3 = new QPushButton;
    QPushButton* btn4 = new QPushButton;
    QPushButton* num[4] = {btn1, btn2, btn3, btn4};

    QPushButton* wbtn1 = new QPushButton;
    QPushButton* wbtn2 = new QPushButton;
    QPushButton* wbtn3 = new QPushButton;
    QPushButton* wbtn4 = new QPushButton;
    QPushButton* wbtn_num[4] = {wbtn1, wbtn2, wbtn3, wbtn4};
    bool m_flag1;
    bool m_flag2;
    bool m_flag3;
    bool m_flag4;
signals:

public slots:
    void update_lbtn();
    void show_page(QWidget* wtr);
    void update_wbtn1();
    void update_wbtn2();
    void update_wbtn3();
    void update_wbtn4();
    int get_mflag1();
    int get_mflag2();
    int get_mflag3();
    int get_mflag4();
};


#endif // DISTRIBUTED_FUN_H
