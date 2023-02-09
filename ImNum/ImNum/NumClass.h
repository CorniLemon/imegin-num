#pragma once

#include <iostream>
using namespace std;

class ImNum {
private:
    double real, im;
public:
    ImNum(double X = 0, double Y = 0)
        : real(X), im(Y)
    {}

    ImNum(const ImNum& p)
        : real(p.real), im(p.im)
    {}

    void print() const {//вывод
        cout << real << "+" << im << "i";
        cout << "\n";
    }

    ImNum operator+(const ImNum& i) const
    {
        return ImNum(real + i.real, im + i.im);
    }

    ImNum operator-(const ImNum& i) const
    {
        return ImNum(real - i.real, im - i.im);
    }

    ImNum& operator=(const ImNum& i)
    {
        this->real = i.real;
        this->im = i.im;
        return *this;
    }

    ImNum operator*(const ImNum& i) const
    {
        return ImNum(real * i.real - im * i.im, real * i.im + i.real * im);
    }

    ImNum Dop() const {
        return ImNum(real, -im);
    }

    ImNum operator/(const ImNum& i) const
    {
        ImNum is = i.Dop();
        double Zn = i.real * i.real + i.im * i.im;
        is = *this * is;
        return ImNum(is.real / Zn, is.im / Zn);
    }

    ImNum& operator++()
    {
        ++real;
        return *this;
    }

    ImNum operator++(int a)
    {
        ImNum is = *this;
        ++real;
        return is;
    }

    ImNum& operator--()
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

    double abs() const {
        return (sqrt(real * real + im * im));
    }

    double arg() const
    {
        return atan2(im, real);
    }

    ImNum operator-() const
    {
        return ImNum(-this->real, -this->im);
    }

    int operator==(const ImNum& i) const
    {
        return (real == i.real) && (im == i.im);
    }

    int operator!=(const ImNum& i) const
    {
        return (real != i.real) || (im != i.im);
    }

    ImNum& operator+=(const ImNum& i)
    {
        real += i.real;
        im += i.im;
        return *this;
    }

    ImNum& operator-=(const ImNum& i)
    {
        real -= i.real;
        im -= i.im;
        return *this;
    }

    ImNum& operator*=(const ImNum& i)
    {
        *this = *this * i;
        return *this;
    }

    ImNum& operator/=(const ImNum& i)
    {
        *this = *this / i;
        return *this;
    }
};

inline double abs(const ImNum& c)
{
    return c.abs();
}