#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //qDebug() << QString("Hello").leftJustified(10, ' ');
    //qDebug() << QString("kek").leftJustified(10, ' ');

    return a.exec();
}
