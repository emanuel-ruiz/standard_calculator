#include "standard_calculator.h"

Standard_Calculator::Standard_Calculator(QObject *parent)
    : QObject{parent}
{

    qInfo() << "Calculator Created";
}


// // slash with two starting asteriks denotes Doxygen comment block
// /**
//     @brief Calculate the greatest common divisor of two integers.
//     @param f First Integer.
//     @param b Second Integer.
//     @return The GCD of the two integers

//     @note Negative numbers with be converted to positive.
// */
