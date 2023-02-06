#pragma once

#include <iostream>
using namespace std;

class ImNum {
private:
    double real, im;
public:
    ImNum()
        : real(0), im(0)
    {}

    ImNum(double X, double Y)
        : real(X), im(Y)
    {}

    ImNum(const ImNum& p)
        : real(p.real), im(p.im)
    {}

    void print() {
        cout << real << "+" << im << "i";
        cout << "\n";
    }

    ImNum operator+(const ImNum& i)
    {
        return ImNum(real + i.real, im + i.im);
    }

    ImNum operator-(const ImNum& i)
    {
        return ImNum(real - i.real, im - i.im);
    }

    ImNum operator=(const ImNum& i)
    {
        return ImNum(real = i.real, im = i.im);
    }

    ImNum operator*(const ImNum& i)
    {
        return ImNum(real*i.real-im*i.im, real*i.im+i.real*im);
    }

    ImNum operator/(const ImNum& i)
    {
        ImNum is(i.real, -i.im);
        double Zn = i.real * i.real + i.im * i.im;
        *this = *this * is;//Нормально ли менять this?
        return ImNum(real/Zn, im/Zn);
    }

    ImNum operator++()//что должен вернуть остаток от деления? 
    {
        return ImNum(real+1,im);
    }

    ImNum operator--()
    {
        return ImNum(real - 1, im);
    }
};