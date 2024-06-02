#ifndef SYNTAX_SING_H
#define SYNTAX_SING_H
#include <QString>
#include "standard_calculator.h"

class Syntax_Sing
{

public:
    static Syntax_Sing& get_instance();
    bool par_syntax(const QString &eq);


    bool isDouble(const QString &eq);

    double calulate_total(const QString &eq, Standard_Calculator &cal);
    void _calculate(QQueue<QChar>& operators, QQueue<int>& values, Standard_Calculator &cal);

    //Delete cpy constructor and assignment operator
    Syntax_Sing(const Syntax_Sing&) = delete;
    Syntax_Sing operator=(const Syntax_Sing&) = delete;


private:
    Syntax_Sing(); //Constructor my be private for singleton design pattern
    ~Syntax_Sing();

};

#endif // SYNTAX_SING_H
