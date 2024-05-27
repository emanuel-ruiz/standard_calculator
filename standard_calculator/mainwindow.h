#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:

signals:

    // QWidget interface
public:
    QSize sizeHint() const override;
};

#endif // MAINWINDOW_H
