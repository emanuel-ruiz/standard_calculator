#include "standard_widget.h"
#include "ui_standard_widget.h"

Standard_Widget::Standard_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Standard_Widget)
{
    ui->setupUi(this);
    ui->edit_numbers->setAlignment(Qt::AlignRight);
    this->cal = new Standard_Calculator(this);

    connect(ui->button_0, &QPushButton::clicked, )

}

Standard_Widget::~Standard_Widget()
{
    delete ui;
}

void Standard_Widget::calculate_equation(QString equation)
{

}

void Standard_Widget::input_slot(QString &eq)
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button){
        qInfo() << "Button Clicked";

        if(button->text() == "0"){

        }else if(button->text()== "1"){

        }else if(button->text()== "2"){

        }else if(button->text()== "3"){

        }else if(button->text()== "4"){

        }else if(button->text()== "5"){

        }else if(button->text()== "6"){

        }else if(button->text()== "7"){

        }else if(button->text()== "8"){

        }else if(button->text()== "9"){

        }else if(button->text()== "+"){

        }else if(button->text()== "-"){

        }else if(button->text()== "*"){

        }else if(button->text()== "X^Y"){

        }else if(button->text()== "√"){

        }else if(button->text()== "X!"){

        }else if(button->text()== "MOD"){

        }else if(button->text()== "÷"){

        }else if(button->text()== "GCD"){

        }else if(button->text()== "C"){

        }else if(button->text()== "CE"){

        }else{

        }
    }


}
