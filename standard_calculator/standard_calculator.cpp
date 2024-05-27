#include "standard_calculator.h"

Standard_Calculator::Standard_Calculator(QObject *parent)
    : QObject{parent}
{}

int Standard_Calculator::factorial(const int &a)
{
    if(a == 0){
        return 1;
    }
    return a * this->factorial(a-1);
}

int Standard_Calculator::modulus(const int &a, const int &b)
{
    if(b == 0){
        return NULL;
    }
    if(a == 0){
        return 0;
    }
    else{
        return a%b;
    }
}

int Standard_Calculator::gcd(const int &a, const int &b)
{

}

template<typename T>
T Standard_Calculator::addition(const T &a, const T &b)
{
    return a + b;
}

template<typename T>
T Standard_Calculator::subtraction(const T &a, const T &b)
{
    return a - b;
}

template<typename T>
T Standard_Calculator::multiplication(const T &a, const T &b)
{
    return a * b;
}

template<typename T>
T Standard_Calculator::division(const T &a, const T &b)
{
    if(b == 0){
        return NULL;
    }
    if(a == 0){
        return 0;
    }
    else{
        return a - b;
    }
}

template<typename T, int>
T Standard_Calculator::exponential(const T &a, int  &p)
{
    if(p)
    T c = a;
    for(int i = 0; i < p; i++ ){
        c = c*a;
    }
}

template<typename T>
T Standard_Calculator::squareRoot(const T &a)
{

}
