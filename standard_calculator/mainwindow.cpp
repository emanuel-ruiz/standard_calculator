#include <QApplication>
#include "mainwindow.h"
#include "standard_widget.h"
#include <QMenuBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    this->setUI();
    sc = new Standard_Widget(this);
    this->setCentralWidget(this->sc);
}

MainWindow::~MainWindow()
{
    delete fileMenu;
}

//Implementing Virtual Function to set default window size.
QSize MainWindow::sizeHint() const
{
    return QSize(600, 700);
}

void MainWindow::setActions()
{
    this->quitAction = new QAction("Quit", this);

    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });
}

void MainWindow::setUI()
{
    this->setActions();
    this->fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(this->quitAction);
}
