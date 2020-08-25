#include <iostream>
#include "Automobile.hpp"

using namespace std;

Automobile::Automobile(string ma, string mo)   //Automobile:: part of the automobile class
{                                              // goes in front of the method names
    make = ma;
    model = mo;
    condition = "new";
}
void Automobile::setCondition(string _condition)
{
    condition = _condition;
}
string Automobile::getCondition()
{
    return condition;
}
int main()
{
    Automobile subaru("subaru", "outback");
    subaru.setCondition("wrecked");
    cout << "Class example "
        << subaru.getCondition() << "\n";

    return 0;
}
