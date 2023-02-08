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

    void print() {//вывод
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

    ImNum Dop(const ImNum& i) {
        return ImNum(i.real, -i.im);
    }

    ImNum operator/(const ImNum& i)
    {
        ImNum is = Dop(i);
        double Zn = i.real * i.real + i.im * i.im;
        *this = *this * is;
        return ImNum(real/Zn, im/Zn);
    }

    ImNum operator++()
    {
        ++real;
        return ImNum(real,im);
    }

    ImNum operator--()
    {
        --real;
        return ImNum(real, im);
    }

    double abs(const ImNum& i) {
        return (sqrt(i.real * i.real + i.im * i.im));
    }

    ImNum operator-()
    {
        return ImNum(-this->real, -this->im);
    }

    int operator==(const ImNum& i)
    {
        if ((real == i.real) && (im == i.im))
            return 1;
        else
            return 0;
    }

    int operator!=(const ImNum& i)
    {
        if ((real == i.real) && (im == i.im))
            return 0;
        else
            return 1;
    }

    ImNum operator+=(const ImNum& i)
    {
        real += i.real;
        im += i.im;
        return ImNum(real, im);
    }

    ImNum operator-=(const ImNum& i)
    {
        real -= i.real;
        im -= i.im;
        return ImNum(real, im);
    }

    ImNum operator*=(const ImNum& i)
    {
        *this = *this * i;
        return ImNum(real, im);
    }

    ImNum operator/=(const ImNum& i)
    {
        *this = *this / i;
        return ImNum(real, im);
    }
};