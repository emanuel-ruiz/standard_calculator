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

double Syntax_Sing::calulate_total(const QString &eq)
{
    QQueue<QChar> operators;
    QQueue<QChar> values;

    double total = 0;
    double temp = 0;
    QString current = "";
    //iterate through list
    //QChar has isDigit
    //QString has toDouble(&ok) ok is bool
    for(QString::const_iterator it = eq.cbegin(); it != eq.cend(); it++){
        QChar ch = *it;
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
