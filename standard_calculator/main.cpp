#include <QApplication>
#include "mainwindow.h"
#include "standard_calculator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Standard Calculator");
    w.show();
    Standard_Calculator *cal = new Standard_Calculator(&w);
    qInfo() << cal->gcd(878, 12);
    return a.exec();
}
