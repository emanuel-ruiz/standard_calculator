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
    for(QChar ch: eq){
        if(ch == '('){
            syntax.push(ch);
        }
        else if(ch == ')'){
            if(syntax.isEmpty()){
                return false;
            }
            syntax.pop();
        }
    }
    if(syntax.isEmpty()){
        return true;
    }
    return false;
}

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
    if(!operators.isEmpty()){
        this->_calculate(operators, values, cal);
    }
    return values.dequeue();
}
//GCD and Factorial will be calculated seperately
void Syntax_Sing::_calculate(QQueue<QChar>& operators, QQueue<int>& values, Standard_Calculator &cal)
{
    int head = 0;
    int next = 0;
    //we do a for loop with the length of the operators

    while(!values.isEmpty() && !operators.isEmpty()){
        QChar op = operators.dequeue();
        if(op == '*'){
            head = values.dequeue();
            int next = values.head();
            values.head() = cal.multiplication(head, next);
        }
        else if(op == '/'){
            head = values.dequeue();
            int next = values.head();
            values.head() = cal.division(head, next);
        }
        else if(op == '^'){
            head = values.dequeue();
            int next = values.head();
            values.head() = cal.exponential(head, next);
        }
        else{
            head = values.dequeue();
            values.enqueue(head);
            operators.enqueue(op);
        }
    }
    while(!operators.isEmpty()){
        QChar op = operators.dequeue();
        head = values.dequeue();
        next = values.dequeue();
        if(op == '+'){
            values.head() = cal.addition(head,next);
        }
        else{
            values.head() = cal.subtraction(head, next);
        }
    }


}

Syntax_Sing::Syntax_Sing()
{
    qInfo() << "Syntax Singleton created";
}

Syntax_Sing::~Syntax_Sing()
{

}
