#include "syntax_sing.h"
#include <stack>
#include <QDebug>



Syntax_Sing &Syntax_Sing::get_instance()
{
    static Syntax_Sing instance;

    return instance;
}

bool Syntax_Sing::par_syntax(QString &eq)
{

}

double Syntax_Sing::calulate_total(QString &eq)
{

}

Syntax_Sing::Syntax_Sing()
{
    qInfo() << "Syntax Singleton created";
}
