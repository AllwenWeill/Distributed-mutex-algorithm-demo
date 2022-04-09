#ifndef DISTRIBUTED_WAITPAGE_H
#define DISTRIBUTED_WAITPAGE_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <string>
#include <QString>
#include <QDebug>
#include <QCloseEvent>  //当程序需要关闭时处理的内容
#include "flag.h"
//bool m_flag1 = 0, m_flag2 = 0, m_flag3 = 0, m_flag4 = 0;
class Distributed_waitpage : public QObject
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent* event);
private:
    bool openFlag = 1;
public:
    explicit Distributed_waitpage(QObject *parent = nullptr);
    void show_waitpage();
    ~Distributed_waitpage();
    int isOpen();

    bool m_flag1;
    bool m_flag2;
    bool m_flag3;
    bool m_flag4;
signals:

public slots:
    void update_wbtn1();
    void update_wbtn2();
    void update_wbtn3();
    void update_wbtn4();
    int get_mflag1();
    int get_mflag2();
    int get_mflag3();
    int get_mflag4();
};

#endif // DISTRIBUTED_WAITPAGE_H
