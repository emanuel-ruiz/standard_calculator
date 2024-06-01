#include "standard_calculator.h"

Standard_Calculator::Standard_Calculator(QObject *parent)
    : QObject{parent}
{

    qInfo() << "Calculator Created";
}

