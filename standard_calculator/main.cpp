#include <QApplication>
#include "mainwindow.h"
#include "standard_calculator.h"
#include "syntax_sing.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Standard Calculator");
    w.show();
    Standard_Calculator cal;

    return a.exec();
}
