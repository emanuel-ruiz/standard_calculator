#include "standard_widget.h"
#include "ui_standard_widget.h"

Standard_Widget::Standard_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Standard_Widget)
{
    ui->setupUi(this);
    ui->edit_numbers->setAlignment(Qt::AlignRight);
    this->cal = new Standard_Calculator(this);

    //Digit Buttons
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

    //Operator buttons and special characters
    connect(ui->button_period, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_lpara, &QPushButton::clicked, this, &Standard_Widget::input_slot);
    connect(ui->button_rPara, &QPushButton::clicked, this, &Standard_Widget::input_slot);
    connect(ui->button_comma, &QPushButton::clicked, this, &Standard_Widget::input_slot);
    connect(ui->button_mod, &QPushButton::clicked, this, &Standard_Widget::input_slot);
    connect(ui->button_plus, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_minus, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_div, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_mult, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_exp, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_equal, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_clear, &QPushButton::clicked,this,&Standard_Widget::input_slot);
    connect(ui->button_back, &QPushButton::clicked, this, &Standard_Widget::input_slot);



    //Square Root, Factorial and GCD buttons
    connect(ui->button_sqrt, &QPushButton::clicked,this,&Standard_Widget::sqr_factorial_input_slot);
    connect(ui->button_factorial, &QPushButton::clicked,this,&Standard_Widget::sqr_factorial_input_slot);
    connect(ui->button_gcd, &QPushButton::clicked, this, &Standard_Widget::gcd_slot);


}

Standard_Widget::~Standard_Widget()
{
    delete ui;
    delete cal;
}


/**
    @brief Dependent on sender object will add to the String Equation or calculate Equation.

*/
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
        }else if(button->text()== "÷"){
            temp.append('/');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "X^Y"){
            temp.append('^');
            ui->edit_numbers->setText(temp);
        }else if(button->text()== "C"){
            ui->edit_numbers->setText("");

        }else if(button->text()== "CE"){

        }else if(button->text() == "."){
            temp.append('.');
            ui->edit_numbers->setText(temp);
        }else if(button->text() == "("){
            temp.append('(');
            ui->edit_numbers->setText(temp);
        }
        else if(button ->text() == ")"){
            temp.append(')');
            ui->edit_numbers->setText(temp);
        }
        else if(button->text() == ","){
            temp.append(',');
            ui->edit_numbers->setText(temp);
        }
        else if(button->text() == "MOD"){
            temp.append('%');
            ui->edit_numbers->setText(temp);
        }
        else if(button->text() == "Backspace"){
            temp.chop(1);
            ui->edit_numbers->setText(temp);
        }
        else{
            //equal was pressed
            //verify equation
            //calculate total
            //display total
            if(Syntax_Sing::get_instance().par_syntax(temp)){
                int total = Syntax_Sing::get_instance().calulate_total(temp, *cal);
                ui->edit_numbers->setText(QString::number(total));
            }else{
                ui->edit_numbers->setText("Syntax Error");
            }
        }

        ui->edit_numbers->setAlignment(Qt::AlignRight);
    }


}

//This slot will be implemented when the user presses the square root, factorial option
/**
 *@brief Slot for the square-root and factorial inputs
 *
*/
void Standard_Widget::sqr_factorial_input_slot()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button){
        QString temp = ui->edit_numbers->toPlainText();
        double dValue = 0.0;
        int iValue = 0;
        bool ok;
        bool doub = Syntax_Sing::get_instance().isDouble(temp);
        if(doub){
            dValue = temp.toDouble();
            if(button->text()== "√"){
                //create function for this
                dValue = this->cal->squareRoot(dValue);
                temp = QString::number(dValue, 'f', 2);
                ui->edit_numbers->setText(temp);
            }
            else{
                ui->edit_numbers->setText("Integer Values Only");
            }

        }else{
            iValue = temp.toInt(&ok);
            if(ok){
                if(button->text()== "√"){
                    dValue = this->cal->squareRoot(iValue);
                    temp = QString::number(dValue,'f',2);
                    ui->edit_numbers->setText(temp);
                }else if(button->text()== "X!"){
                    iValue = this->cal->factorial(iValue);
                    temp = QString::number(iValue);
                    ui->edit_numbers->setText(temp);
                }
            }else{
                ui->edit_numbers->setText("Syntax Error");
            }
        }
        ui->edit_numbers->setAlignment(Qt::AlignRight);

    }
}
/**
    @brief Slot function for GCD function push button
           Checks for Syntax Prior to calling the GCD Funtion in Calculator.


*/
void Standard_Widget::gcd_slot()
{
    QString temp = ui->edit_numbers->toPlainText();
    QList<QString> values = temp.split(',');
    if(values.size() == 2){
        for(int i = 0;i < values.size(); i++){
            QString ch = values.at(i);
            ch = ch.trimmed();
            values[i] = ch;
            if(Syntax_Sing::get_instance().isDouble(ch)){
                ui->edit_numbers->setText("Integer Values Only");
            }
        }

        bool toInt;
        bool toInt2;
        int first = values[0].toInt(&toInt);
        int second = values[1].toInt(&toInt2);
        int gcd = this->cal->gcd(first, second);
        if(toInt && toInt2){
            ui->edit_numbers->setText(QString::number(gcd));
            ui->edit_numbers->setAlignment(Qt::AlignRight);
        }
    }
    else{
        ui->edit_numbers->setText("Only Two Values Allowed");
    }

}

