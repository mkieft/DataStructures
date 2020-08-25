///file Complex.cpp
#include "complex.hpp"
#include <iostream>

Complex::Complex()
{

}

void Complex::setData(double _real, double _imag)
{
  real = _real;
  imag = _imag;
}
void Complex::printComplexNumber()
{
   std::cout << "(" << real << "," << imag << "i)" << std::endl;
}
double Complex::getReal() ///show that this is a method part of complex class (complex:: look inside complex class))
{
    return real;
}
double Complex::getImag()
{
    return imag;
}

void Complex::setReal(double _real) ///set variable fo rsetters
{
    real = _real;
}
void Complex::setImag(double _imag)
{
    imag = _imag;
}
Complex Complex::add(Complex &complexOther)
{
    Complex complexSum;
    complexSum.real = real + complexOther.getReal();
    complexSum.imag = imag + complexOther.getImag();

    return complexSum;
}
Complex Complex::subtract(Complex &complexOther)
{
    Complex complexDiff;
    complexDiff.real = real - complexOther.getReal();
    complexDiff.imag = imag - complexOther.getImag();
}
