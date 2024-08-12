#ifndef STANDARD_WIDGET_H
#define STANDARD_WIDGET_H





#include "standard_calculator.h"
#include <QWidget>

/**
* @abstract Widget that will represent the standard calculator
* interface.
*/
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
    void input_slot();
    void sqr_factorial_input_slot();
    void gcd_slot();

};

#endif // STANDARD_WIDGET_H
