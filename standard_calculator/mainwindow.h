#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "standard_calculator_widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSize sizeHint() const override;
    void setActions();
    void setUI();

    standard_calculator_widget *sc;
    QAction *quitAction;
    QMenu *fileMenu;
signals:

    // QWidget interface
public:

};

#endif // MAINWINDOW_H
