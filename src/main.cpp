#include "mywidget.h"
#include <QApplication>
#include <queue>
#include <string>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.show();

    return a.exec();
}
