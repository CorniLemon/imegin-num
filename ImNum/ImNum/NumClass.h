#pragma once

#include <iostream>
#include <ostream>
using namespace std;

template<class T1>
struct AbsType
{
    using type = T1;
};

template<>
struct AbsType<int>
{
    using type = double;
};

template<>
struct AbsType<unsigned int>
{
    using type = double;
};

template<>
struct AbsType<long long>
{
    using type = long double;
};

template<>
struct AbsType<unsigned long long>
{
    using type = long double;
};

template<>
struct AbsType<long>
{
    using type = double;
};

template<>
struct AbsType<unsigned long>
{
    using type = double;
};

template<>
struct AbsType<short>
{
    using type = float;
};

template<>
struct AbsType<unsigned short>
{
    using type = float;
};

template<>
struct AbsType<char>
{
    using type = float;
};

template<>
struct AbsType<unsigned char>
{
    using type = float;
};

template<class Tglob>
class ImNum {
private:
    Tglob real, im;
public:
    ImNum(Tglob X = 0, Tglob Y = 0)
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

    ImNum operator+(const Tglob& i) const
    {
        return ImNum(real + i, im);
    }

    ImNum operator-(const ImNum& i) const
    {
        return ImNum(real - i.real, im - i.im);
    }

    ImNum operator-(const Tglob& i) const
    {
        return ImNum(real - i, im);
    }

    ImNum& operator=(const ImNum& i)
    {
        this->real = i.real;
        this->im = i.im;
        return *this;
    }

    ImNum& operator=(const Tglob& i)
    {
        this->real = i;
        this->im = 0;
        return *this;
    }

    ImNum operator*(const ImNum& i) const
    {
        return ImNum(real * i.real - im * i.im, real * i.im + i.real * im);
    }

    ImNum operator*(const Tglob& i) const
    {
        return ImNum(real * i,+ i * im);
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

    ImNum operator/(const Tglob& i) const
    {
        return ImNum(real / i, im / i);
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

    typename AbsType<Tglob>::type abs() const
    {
        return sqrt((typename AbsType<Tglob>::type)real * real + (typename AbsType<Tglob>::type)im * im);
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
        //cout << "ImNum\n";
        return *this;
    }

    ImNum& operator+=(const Tglob& i)
    {
        real += i;
        //cout << "double\n";
        return *this;
    }

    ImNum& operator-=(const ImNum& i)
    {
        real -= i.real;
        im -= i.im;
        return *this;
    }

    ImNum& operator-=(const Tglob& i)
    {
        real -= i;
        return *this;
    }

    ImNum& operator*=(const ImNum& i)
    {
        *this = *this * i;
        return *this;
    }

    ImNum& operator*=(const Tglob& i)
    {
        *this = *this * i;
        return *this;
    }

    ImNum& operator/=(const ImNum& i)
    {
        *this = *this / i;
        return *this;
    }

    ImNum& operator/=(const Tglob& i)
    {
        *this = *this / i;
        return *this;
    }

    Tglob operator[](size_t index)
    {
        return index ? im : real;
    }

    template<class Tglob>
    friend inline ostream& operator<<(ostream& s, const ImNum<Tglob>& c);

    //template<class Tglob>
    //friend inline ostream& operator>>(ostream& s, ImNum<Tglob>& c);

    template<class Tglob>
    friend inline typename AbsType<Tglob>::type abs(const ImNum<Tglob>& c);

    template<class Tglob>
    friend inline int CompReal(const ImNum<Tglob>& v1, const ImNum<Tglob>& v2);

    template<class Tglob>
    friend inline int CompIm(const ImNum<Tglob>& v1, const ImNum<Tglob>& v2);
};

template<class Tglob>
inline ostream& operator<<(ostream& s, const ImNum<Tglob>& c)
{
    s << c.real << (c.im >= 0 ? "+" : "-") << abs(c.im) << "i";
    return s;
}

//template<class Tglob>
//inline ostream& operator>>(ostream& s, ImNum<Tglob>& c)
//{
//    char i; // для чтения + - i
//    s >> c.real;
//    s >> i;
//    s >> c.im;
//    s >> i;
//    return s;
//}

template<class Tglob>
inline typename AbsType<Tglob>::type abs(const ImNum<Tglob>& c)
{
    return sqrt((typename AbsType<Tglob>::type)c.real * c.real + (typename AbsType<Tglob>::type)c.im * c.im);
}

template<class Tglob>
 inline int CompReal(const ImNum<Tglob>& v1, const ImNum<Tglob>& v2)//сравнение 2 элем по real
{
    return v1.real > v2.real ? 1 : (v1.real < v2.real ? -1 : 0);
}

 template<class Tglob>
 inline int CompIm(const ImNum<Tglob>& v1, const ImNum<Tglob>& v2)//сравнение 2 элем по real
 {
     return v1.im > v2.im ? 1 : (v1.im < v2.im ? -1 : 0);
 }