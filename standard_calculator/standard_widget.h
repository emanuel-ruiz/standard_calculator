#ifndef STANDARD_WIDGET_H
#define STANDARD_WIDGET_H

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
};

#endif // STANDARD_WIDGET_H
