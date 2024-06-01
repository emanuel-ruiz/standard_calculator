#include "standard_widget.h"
#include "ui_standard_widget.h"

Standard_Widget::Standard_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Standard_Widget)
{
    ui->setupUi(this);
    ui->edit_numbers->setAlignment(Qt::AlignRight);
    this->cal = new Standard_Calculator(this);

    connect(ui->button_0, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_1, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_2, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_3, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_4, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_5, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_6, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_7, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_8, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_9, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_plus, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_minus, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_div, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_factorial, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_gcd, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_sign, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_sqrt, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_mult, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_clear, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_clearA, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_exp, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_equal, &QPushButton::clicked,this,&Standard_Widget::input_slot);


}

Standard_Widget::~Standard_Widget()
{
    delete ui;
}

void Standard_Widget::calculate_equation()
{

}

void Standard_Widget::input_slot()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button){

        QString temp = ui->edit_numbers->toPlainText();
        if(button->text() == "0"){

            temp.append('0');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "1"){
            temp.append('1');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "2"){
            temp.append('2');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "3"){
            temp.append('3');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "4"){
            temp.append('4');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "5"){
            temp.append('5');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "6"){
            temp.append('6');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "7"){
            temp.append('7');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "8"){
            temp.append('8');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "9"){
            temp.append('9');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "+"){
            temp.append("+");
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "-"){
            temp.append('-');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "*"){
            temp.append('*');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "X^Y"){
            temp.append('^');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "√"){
            temp.append('s');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "X!"){
            temp.append('!');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "MOD"){
            temp.append('%');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "÷"){
            temp.append('/');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "GCD"){
            temp.append('g');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "C"){


        }else if(button->text()== "CE"){

        }else{

        }
        ui->edit_numbers->setAlignment(Qt::AlignRight);
    }


}
