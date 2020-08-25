#include <iostream>
#include "HW4-Todo-StackArray.hpp"
// #include "StackLL.cpp"
using namespace std;

int main()
{
    TodoStackArray stack;

stack.push("Hello");

cout<< (stack.peek())->todo<< endl;

stack.push("This");

cout<< stack.getStackTop() << endl;

cout<< stack.peek()->todo<<endl;

stack.push("IS");

cout<< stack.peek()->todo<<endl;

stack.push("My");

cout<< stack.getStackTop() << endl;

cout<< stack.peek()->todo<<endl;

stack.push("List");

cout<< stack.peek()->todo<<endl;

stack.push("Stack"); //Overflow condition

stack.pop();

cout<< stack.peek()->todo<<endl;

stack.pop();

cout<< stack.getStackTop() << endl;

cout<< stack.peek()->todo<<endl;

stack.pop();

cout<< stack.peek()->todo<<endl;

stack.pop();

cout<< stack.getStackTop() << endl;

cout<< stack.peek()->todo<<endl;

stack.pop();

stack.pop();
    return 0;
}
