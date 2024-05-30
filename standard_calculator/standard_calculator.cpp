#include "standard_calculator.h"

Standard_Calculator::Standard_Calculator(QObject *parent)
    : QObject{parent}
{

    qInfo() << "Calculator Created";
}

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

int Standard_Calculator::gcd(const int f, const int s)
{
    //Eucledian Algorithm
    //a = bq + r
    if(f ==0 && s != 0) return s;
    if(s == 0 && f !=0) return f;
    if(f == 0 && s==0) return NULL;


    int a = (f>s) ? f: s;
    int b = (s<f) ? s: f;

    int r = a%b;
    if(r == 0){
        return b;
    }
    int q = a/b;
    qInfo() << a << "-" << b << "-" << r;
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
        return a/b;
    }
}

template<typename T, int N>
T Standard_Calculator::exponential(const T &a, const int  &p)
{
    if(p == 0){
        return 1;
    }
    T c = a;
    for(int i = 0; i < p; i++ ){
        c = c*a;
    }
}

template<typename T>
T Standard_Calculator::squareRoot(const T &a)
{
    if(a < 0 ){
        return NULL;
    }
    return std::sqrt(a);
}
