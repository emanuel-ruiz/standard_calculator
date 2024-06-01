#include "syntax_sing.h"
#include "standard_calculator.h"
#include <QStack>
#include <QDebug>
#include <QQueue>


Syntax_Sing &Syntax_Sing::get_instance()
{
    static Syntax_Sing instance;
    return instance;
}

/**

*/
bool Syntax_Sing::par_syntax(const QString &eq)
{
    QStack<QChar> syntax;
    QChar previous;
    for(QChar ch: eq){

        if(ch == '('){
            syntax.push(ch);
        }
        else if(ch == ')'){
            if(syntax.isEmpty()){
                return false;
            }
            if(previous == '+' || previous == '-' || previous == '*' || previous =='/' || previous == '^' || previous == '%'){
                return false;
            }
            syntax.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch =='/' || ch == '^' || ch == '%'){
            if(previous == '('){
                return false;
            }

        }
        previous = ch;
    }
    if(syntax.isEmpty()){
        return true;
    }
    return false;
}

bool Syntax_Sing::isDouble(const QString &eq)
{
    return false;
}

//CURRENT STATE IS ONLY FOR INTEGERS
double Syntax_Sing::calulate_total(const QString &eq, Standard_Calculator &cal)
{
    QQueue<QChar> operators;
    QQueue<int> values;

    QString current = "";
    //iterate through list
    //QChar has isDigit
    //QString has toDouble(&ok) ok is bool
    for(QString::const_iterator it = eq.cbegin(); it != eq.cend(); it++){
        QChar ch = *it;
        if(ch.isDigit()){
            current.append(ch);
            qInfo() << current;
        }else{
            //if ch is anything besides a digit, then the running value is complete
            if(!current.isEmpty()){
                values.append(current.toInt());
                current.clear();
            }
            if(ch == ' '){
                continue;
            }
            if(ch != ' ' && ch != '(' && ch != ')'){
                operators.append(ch);
            }
            if(ch == ')'){
                if(!operators.isEmpty()){
                    this->_calculate(operators, values, cal);
                }
            }
        }
    }
    //Equation ends with a digit
    if(!current.isEmpty()){
        values.append(current.toInt());
        current.clear();
    }

    //Equation does not end with a closing paranthesis
    if(!operators.isEmpty()){

        qInfo()<< values;
        qInfo() << operators;
        this->_calculate(operators, values, cal);
    }
    return values.dequeue();
}
//GCD and Factorial will be calculated seperately
void Syntax_Sing::_calculate(QQueue<QChar>& operators, QQueue<int>& values, Standard_Calculator &cal)
{

    //TODO FIND A Way to get out of loop
    int head = 0;
    int next = 0;
    QChar op;
    //we do a for loop with the length of the operators
    int length = operators.size();

    for(int i = 0; i < length; i++){

        op = operators.dequeue();
        head = values.dequeue();
        next = values.head();

        if(op == '*'){
            values.head() = cal.multiplication(head, next);
        }
        else if(op == '/'){
            values.head() = cal.division(head, next);
        }
        else if(op == '^'){
            values.head() = cal.exponential(head, next);
        }
        else{
            values.enqueue(head);
            operators.enqueue(op);
        }
        qInfo() << values;
        qInfo() << operators;
    }
    qInfo() << "------------------------------";
    while(!operators.isEmpty()){

        QChar op = operators.dequeue();
        head = values.dequeue();
        next = values.head();
        if(op == '+'){
            values.head() = cal.addition(head,next);
        }
        else{
            if(head > next){
                values.head() = cal.subtraction(head, next);
            }
            values.head() = cal.subtraction(next, head);
        }
        qInfo() << values;
        qInfo() << operators;
    }


}

Syntax_Sing::Syntax_Sing()
{
    qInfo() << "Syntax Singleton created";
}

Syntax_Sing::~Syntax_Sing()
{

}
