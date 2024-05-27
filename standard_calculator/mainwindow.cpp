#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{}


QSize MainWindow::sizeHint() const
{
    return QSize(600, 700);
}
