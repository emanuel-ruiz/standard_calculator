#ifndef STANDARD_CALCULATOR_H
#define STANDARD_CALCULATOR_H

#include <QObject>
#include <QDebug>


/**
* @ abstract Standard Calculator that will implement
* Standard operators including factorial, exponents, square root
* along with calculating the Greatest Common Denominator between two integer values;
*/
class Standard_Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Standard_Calculator(QObject *parent = nullptr): QObject{parent}{};

    template<typename T>
    T addition(const T &a, const T &b){
        return a + b;
    }

    template<typename T>
    T subtraction(const T &a, const T &b){
        return a -b;
    }

    template<typename T>
    T multiplication(const T &a, const T &b){
        return a *b;
    }

    template<typename T>
    T division(const T &a, const T &b)
    {
        if(b == 0){
            return NULL;
        }
        if(a == 0){
            return 0;
        }
        else{
            return a/b;
        }
    }

    double exponential(const double &a, const double &b ){
        if(b == 0){
            return 1;
        }
        double c = a;
        for(int i = 0; i < b-1; i++ ){
            c = c*a;
        }
        return c;
    }


    double squareRoot(const double &a)
    {
        if(a < 0 ){
            return NULL;
        }
        return std::sqrt(a);
    }

    int factorial(const int &a)
    {
        if(a == 0){
            return 1;
        }
        return a * this->factorial(a-1);
    }

    int modulus(const int &a, const int &b)
    {
        if(b == 0){
            return 0;
        }
        if(a == 0){
            return 0;
        }
        else{
            return a%b;
        }
    }
    // slash with two starting asteriks denotes Doxygen comment block
    /**
    @brief Calculate the greatest common divisor of two integers.
    @param f First Integer.
    @param b Second Integer.
    @return The GCD of the two integers

    @note Negative numbers with be converted to positive.
*/
    int gcd(const int f, const int s)
    {

        if(f ==0 && s != 0) return s;
        if(s == 0 && f !=0) return f;
        if(f == 0 && s==0) return 0;



        int a = (f>s) ? f: s;
        int b = (s<f) ? s: f;

        a = std::abs(a);
        b = std::abs(b);
        int r = a%b;
        if(r == 0){
            return b;
        }
        int q = a/b;
        qInfo() << a << "-" << b << "-" << r;
        //Euclidean Algorithm
        while(q != 0 && r !=0){
            a = b;
            b = r;
            r = a%b;
            q = a/b;
        }
        if(r != 0){
            return 1;
        }
        return b;
    }

private:

signals:
};

#endif // STANDARD_CALCULATOR_H
