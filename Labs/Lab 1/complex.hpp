///File complex.hpp
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex{
private:
    double real;
     double imag;
  public:
        Complex( );
        void setData(double _real, double _imag);
        void printComplexNumber();
        double getReal(); //returns type of real
        double getImag(); //getter returns

        ///setters: to set real component must add somehting that has access to do it for us
        void setReal(double _real); //returns nothing - want to set / pas sin real var ot set
        void setImag(double _real);

        ///new function that adds complex #s together
        Complex add(Complex &complexOther);

        Complex subtract(Complex &complexOther);
};



#endif // COMPLEX_HPP
