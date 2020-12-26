#include <iostream>
#include "Methods.h"

ComplexNumber operator+(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;

    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;

    return result;
}

void operator+=(ComplexNumber &a, ComplexNumber b) {
    a = a + b;
}

ComplexNumber operator-(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;

    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;

    return result;
}

void operator-=(ComplexNumber &a, ComplexNumber b) {
    a = a - b;
}

ComplexNumber operator*(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;

    result.real = (a.real * b.real) - (b.imaginary * a.imaginary);
    result.imaginary = (a.real * b.imaginary) + (b.real * a.imaginary);

    return result;
}

void operator*=(ComplexNumber &a, ComplexNumber b) {
    a = a * b;
}

ComplexNumber operator/(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;
    double numerator = 0;   //числитель
    double denominator = 0; //знаминатель

    if ((b.real == 0) && (b.imaginary == 0)) {
        throw std::logic_error(ERROR);
        //std::cout << ERROR << std::endl;
    }

    else {
        //считаем действительную часть
        numerator = (a.real * b.real) + (a.imaginary * b.imaginary);
        denominator = (b.real * b.real) + (b.imaginary * b.imaginary);
        result.real = numerator / denominator;

        //считаем мнимую часть
        numerator = (b.real * a.imaginary) - (a.real * b.imaginary);
        result.imaginary = numerator / denominator;
    }
    return result;
}

void operator/=(ComplexNumber &a, ComplexNumber b) {
    a = a / b;
}

std::ostream& operator<<(std::ostream& out, ComplexNumber a) {
    if ((a.real == 0) && (a.imaginary == 0))
        out << 0 << std::endl;
    else if (a.real == 0)
        out << a.imaginary << 'i' << std::endl;
    else if (a.imaginary == 0)
        out << a.real << std::endl;
    else {
        out << a.real;
        if (a.imaginary > 0)
            if (a.imaginary == 1)
                out << '+' << 'i' << std::endl;
            else
                out << '+' << a.imaginary << 'i' << std::endl;
        else
            if (a.imaginary == -1)
                out << "-i" << std::endl;
            else
                out << a.imaginary << 'i' << std::endl;
    }
}

