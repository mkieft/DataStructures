#include <iostream>
#include "HW4-Todo-StackArray.hpp"

using namespace std;

TodoStackArray::TodoStackArray()
{
  stackTop = nullptr;
}

TodoStackArray::~TodoStackArray()
{
  while(!isEmpty())
  {
    pop();
  }
}

bool TodoStackArray::isEmpty()
{
    return (stackTop == nullptr);
}

void TodoStackArray::push(int key)
{
  // 1. empty
  // 2. not empty
  Node* newNode = new Node;
  newNode->key = key;
  newNode->next = stackTop;
  stackTop= newNode;
}

void TodoStackArray::pop()
{
  // stack not empty
  if(!isEmpty())
  {
    Node* tempPtr = stackHead;
    stackTop = stackTop->next;
    delete tempPtr;
  }
  //stack empty
  //else
  //dont do anything,
  // you can print, return error or catch it


}

int TodoStackArray::peek()
{
  if(stackTop == nullptr)
  {
    // error: empty stack
    //throw ValueError;
    return 0;
  }
  return stackTop->key;
}
