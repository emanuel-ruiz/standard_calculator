#ifndef STANDARD_WIDGET_H
#define STANDARD_WIDGET_H

#include "syntax_sing.h"
#include "standard_calculator.h"
#include <QWidget>

namespace Ui {
class Standard_Widget;
}

class Standard_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Standard_Widget(QWidget *parent = nullptr);
    ~Standard_Widget();

private:
    Ui::Standard_Widget *ui;
    Standard_Calculator *cal;

private slots:
    void calculate_equation(QString equation);
};

#endif // STANDARD_WIDGET_H
