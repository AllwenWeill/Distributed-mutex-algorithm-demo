#include "new_menu.h"

New_menu::New_menu(QObject *parent) : QObject(parent)
{

}
void New_menu::show_centration()
{
    QWidget* wtr2 = new QWidget;
    CentrationFun* CF = new CentrationFun;
    CF->show_page(wtr2);
    wtr2->setWindowTitle("Centration System demo");
    wtr2->setFixedSize(500,400);
    wtr2->show();
}
void New_menu::show_disturbted()
{
    QWidget* wtr1 = new QWidget;
    DistributedFun* DF = new DistributedFun;
    DF->show_page(wtr1);
    DF->show_waitpage();
    wtr1->setWindowTitle("Distributed System demo");
    wtr1->setFixedSize(800,800);
    wtr1->show();
}
void New_menu::show_designer()
{
    QWidget* wtr = new QWidget;
    QLabel*lab1 = new QLabel;
    lab1->setText("Distributed System demo v1.0 is designed by @Allwen_Tech.\nIf you have any questions or suggestions about this demo,please contact me via the QQ number is 1041268906.");
    lab1->setParent(wtr);
    lab1->show();
    wtr->setWindowTitle("Designer Information");
    wtr->setFixedSize(800,800);
    wtr->show();
}
