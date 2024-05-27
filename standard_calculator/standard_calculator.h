#ifndef STANDARD_CALCULATOR_H
#define STANDARD_CALCULATOR_H

#include <QObject>

/*Standard Calculator that will implement
* Addition
* Subtraction
* Multiplication
* Division
* Modulus
* Exponents
* Square Root
*/
class Standard_Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Standard_Calculator(QObject *parent = nullptr);

    template<typename T>
    T addition(const T &a, const T &b);

    template<typename T>
    T subtraction(const T &a, const T &b);

    template<typename T>
    T multiplication(const T &a, const T &b);

    template<typename T>
    T division(const T &a, const T &b);

    template<typename T>
    T exponential(const T &a, const int &p);

    template<typename T>
    T squareRoot(const T &a);

    int factorial(const int &a);

    int modulus(const int &a, const int &b);

    int gcd(const int &a, const int &b);

private:

signals:
};

#endif // STANDARD_CALCULATOR_H
