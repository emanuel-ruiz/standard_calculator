#ifndef SYNTAX_SING_H
#define SYNTAX_SING_H
#include <QString>

class Syntax_Sing
{

public:
    static Syntax_Sing& get_instance();
    bool par_syntax(QString &eq);

    double calulate_total(QString &eq);

    //Delete cpy constructor and assignment operator
    Syntax_Sing(const Syntax_Sing&) = delete;
    Syntax_Sing operator=(const Syntax_Sing&) = delete;

private:
    Syntax_Sing(); //Constructor my be private for singleton design pattern
    ~Syntax_Sing();

};

#endif // SYNTAX_SING_H
