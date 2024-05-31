#include "syntax_sing.h"

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

double Syntax_Sing::_calculate(QQueue<QChar>& operators, QQueue<int>& values, Standard_Calculator &cal)
{
    int head = 0;
    int next = 0;
    //we do a for loop
    QChar op = operators.dequeue();
    if(op == '*'){
        head = values.dequeue();
        int next = values.head();
        values.head() = cal.multiplication(head, next);

    }
    return 0;
}

Syntax_Sing::Syntax_Sing()
{
    qInfo() << "Syntax Singleton created";
}

Syntax_Sing::~Syntax_Sing()
{

}
