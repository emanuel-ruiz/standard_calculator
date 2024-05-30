#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "standard_widget.h"

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

    Standard_Widget *sc;
    QAction *quitAction;
    QMenu *fileMenu;
signals:

    // QWidget interface
public:

};

#endif // MAINWINDOW_H
