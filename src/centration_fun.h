#ifndef CENTRATION_FUN_H
#define CENTRATION_FUN_H
#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <string>
#include <QString>
#include <QDebug>
#include <QQueue>
#include <QTimer>
#include <unordered_map>
#include <QVector>
class CentrationFun:public QObject{
    Q_OBJECT
public:
    explicit CentrationFun(QObject *parent = nullptr);
    ~CentrationFun();
    void update();
    void show_page(QWidget* wtr);
    void update_queue();
    QQueue<QPushButton*> BtnQueue;//其实用QVector更方便,但牵涉东西太多,作者不想更改了QAQ..
    void ShowBtn(int x);
    int IsExist();
    void ExamWait();
signals:
private:
    QPushButton* btn1 = new QPushButton;
    QPushButton* btn2 = new QPushButton;
    QPushButton* btn3 = new QPushButton;
    QPushButton* btn4 = new QPushButton;
    QPushButton* btn_num[4] = {btn1, btn2, btn3, btn4};
    int flag1;
    int flag2;
    int flag3;
    int flag4;
    bool m_flag1;
    bool m_flag2;
    bool m_flag3;
    bool m_flag4;
    int move_x[4] = {50, 150, 250, 350};
    int count;
    //QQueue<int> WaitNum;
    QVector<int> WaitNum;
public slots:
};
void SetQueueLabel(QWidget* ptr);
#endif // CENTRATION_FUN_H
