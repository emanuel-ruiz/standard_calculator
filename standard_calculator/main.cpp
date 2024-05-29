#include <QApplication>
#include "mainwindow.h"
#include "standard_calculator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Standard_Calculator *cal = new Standard_Calculator(&w);
    qInfo() << cal->gcd(10, 5);
    w.setWindowTitle("Standard Calculator");
    w.show();
    return a.exec();
}
