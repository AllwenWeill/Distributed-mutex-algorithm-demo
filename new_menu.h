#ifndef NEW_MENU_H
#define NEW_MENU_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <string>
#include <QString>
#include <QDebug>
#include "distributed_fun.h"
#include "centration_fun.h"

class New_menu : public QObject
{
    Q_OBJECT
public:
    explicit New_menu(QObject *parent = nullptr);

signals:

public slots:
    void show_centration();   //Error:无法在该 槽函数中加参数？？
    void show_disturbted();
    void show_designer();
};

#endif // NEW_MENU_H
