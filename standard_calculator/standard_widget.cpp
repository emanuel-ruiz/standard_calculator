#include "standard_widget.h"
#include "ui_standard_widget.h"

Standard_Widget::Standard_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Standard_Widget)
{
    ui->setupUi(this);
}

Standard_Widget::~Standard_Widget()
{
    delete ui;
}
