/* Mohammed Hejazi
 Homework 4
 Boese
*/
#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"
using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
  stackHead = nullptr;
}
TodoStackLinkedList::~TodoStackLinkedList()
{
  while(!isEmpty())
  {
    pop();
  }
}
bool TodoStackLinkedList::isEmpty()
{
  return (stackHead == nullptr);
}
void TodoStackLinkedList::push(string todoItem)
{
  if(!isEmpty())
  {

  TodoItem* newTodoItem = new TodoItem;
  newTodoItem->todo = todoItem;
  newTodoItem->next = stackHead;
  stackHead = newTodoItem;
}
  if(isEmpty())
  {
    TodoItem* newTodoItem = new TodoItem;
    newTodoItem->todo = todoItem;
    newTodoItem->next = nullptr;
    stackHead = newTodoItem;
  }
}
void TodoStackLinkedList::pop()
{
  if(isEmpty())
  {
    cout << "Stack empty, cannot pop an item." << endl;
  }
  if(!isEmpty())
  {
    TodoItem* tempPtr = stackHead;
    stackHead = stackHead->next;
    delete tempPtr;
  }
}

TodoItem* TodoStackLinkedList::peek()
{
  if(isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
  }
  return stackHead;
}
