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
    return 0;
}

Syntax_Sing::Syntax_Sing()
{
    qInfo() << "Syntax Singleton created";
}

Syntax_Sing::~Syntax_Sing()
{

}
