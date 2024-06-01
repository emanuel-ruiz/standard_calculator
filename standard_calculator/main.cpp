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
    // Standard_Calculator *cal = new Standard_Calculator(&w);
    int answer = Syntax_Sing::get_instance().calulate_total("(4+4*2)", cal);
    qInfo() << answer;
    return a.exec();
}
