#ifndef AUTOMOBILE_HPP_INCLUDED
#define AUTOMOBILE_HPP_INCLUDED

#include <string>

class Automobile
{
private:
    std::string make;                   //have to use std:: anywhere there is string
    std::string model;
    std::string condition;
public:
    Automobile(std::string ma,std::string mo);
    void setCondition (std::string _condition);
    std::string getCondiiton();
};

#endif // AUTOMOBILE_HPP_INCLUDED
