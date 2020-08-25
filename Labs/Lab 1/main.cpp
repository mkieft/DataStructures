///file Main.cpp
#include "complex.cpp"      ///usually .hpp
#include <iostream>

using namespace std;
int main()
{
  Complex c1,c2; // Objects of “complex” class
  c1.setData(2, 3);
  c2.setData(14.3, 22.1);

  ///cmd line args
  ///int main(int arc, char* argv[])
  ///Complex c3;
  ///c3.setReal(stod(argv[1]));
  ///c3.setImag(stod(argv[2]));
  ///c3.printComplexNumber();

  cout << "First complex: "; c1.printComplexNumber();
  cout << "Second complex: ";c2.printComplexNumber();

  //test getters
  cout << "C1 real: " << c1.getReal()<<endl;
  cout << "C1 Imag: " << c1.getImag() <<endl;

  //test setters
  c1.setReal(3);
  c1.setImag(4);
  c1.printComplexNumber();

  //test addition
  Complex sum = c1.add(c2);
  sum.printComplexNumber();

  //test subtraction
  Complex diff = c1.subtract(c2); //c1-c2
  diff.printComplexNumber();

  return 0;
}

