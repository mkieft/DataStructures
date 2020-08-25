#include <iostream>
using namespace std;
#include "HW4-Todo-StackArray.hpp"

TodoStackArray::TodoStackArray()
{
  stackTop = -1;

}
bool TodoStackArray::isEmpty()
{
  if(stackTop == -1)
  {
    return true;
  }
    return false;
}
bool TodoStackArray::isFull()
{
  if(stackTop == MAX_STACK_SIZE - 1)
  {
    return true;
  }
  return false;
}

void TodoStackArray::push(string todoItem)
{
  /*if(isEmpty())
  {
    TodoItem* nextTodo = new TodoItem;
    nextTodo->todo = todoItem;
    stack[stackTop] = nextTodo;
    stackTop++;
    return;
  }*/
  if(isFull())
  {
    cout << "Stack full, cannot add new todo item." << endl;
    return;
  }

    stackTop++;
    TodoItem* nextTodo = new TodoItem;
    nextTodo->todo = todoItem;
    stack[stackTop] = nextTodo;
    return;


}
void TodoStackArray::pop()
{
  if(isEmpty())
  {
    cout << "Stack empty, cannot pop an item." << endl;
    return;
  }
  if(!isEmpty())
  {
    stackTop --;
  }
}
TodoItem* TodoStackArray::peek()
{
  if(isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
    return nullptr;
  }
  return stack[stackTop];
}
