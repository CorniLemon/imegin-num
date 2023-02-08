#pragma once

#include <iostream>
using namespace std;

class ImNum {
private:
    double real, im;
public:
    ImNum(double X=0, double Y=0)
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
        this->real = i.real;
        this->im = i.im;
        return *this;
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
        is = *this * is;
        return ImNum(is.real/Zn, is.im/Zn);
    }

    ImNum operator++()
    {
        ++real;
        return *this;
    }

    ImNum operator++(int a)
    {
        ImNum is=*this;
        ++real;
        return is;
    }

    ImNum operator--()
    {
        --real;
        return *this;
    }

    ImNum operator--(int a)
    {
        ImNum is = *this;
        --real;
        return is;
    }

    double abs() {
        return (sqrt(real * real + im * im));
    }

    ImNum operator-()
    {
        return ImNum(-this->real, -this->im);
    }

    int operator==(const ImNum& i)
    {
        return (real==i.real)&&(im==i.im);
    }

    int operator!=(const ImNum& i)
    {
            return (real!=i.real)||(im!=i.im);
    }

    ImNum operator+=(const ImNum& i)
    {
        real += i.real;
        im += i.im;
        return *this;
    }

    ImNum operator-=(const ImNum& i)
    {
        real -= i.real;
        im -= i.im;
        return *this;
    }

    ImNum operator*=(const ImNum& i)
    {
        *this = *this * i;
        return *this;
    }

    ImNum operator/=(const ImNum& i)
    {
        *this = *this / i;
        return *this;
    }
};