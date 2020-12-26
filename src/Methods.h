#pragma once

#define ERROR "Выражение делится на ноль!"

struct ComplexNumber {
    double real = 0;
    double imaginary = 0;
};

ComplexNumber operator+(ComplexNumber a, ComplexNumber b);
void operator+=(ComplexNumber& a, ComplexNumber b);
ComplexNumber operator-(ComplexNumber a, ComplexNumber b);
void operator-=(ComplexNumber& a, ComplexNumber b);
ComplexNumber operator*(ComplexNumber a, ComplexNumber b);
void operator*=(ComplexNumber& a, ComplexNumber b);
ComplexNumber operator/(ComplexNumber a, ComplexNumber b);
void operator/=(ComplexNumber &a, ComplexNumber b);
std::ostream& operator<<(std::ostream& out, ComplexNumber a);
