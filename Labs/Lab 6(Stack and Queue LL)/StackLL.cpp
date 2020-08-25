#include <iostream>
#include "StackLL.hpp"

using namespace std;

StackLL::StackLL()
{
  stackHead = nullptr;
}

StackLL::~StackLL()
{
  while(!isEmpty())
  {
    pop();
  }
}

bool StackLL::isEmpty()
{
    return (stackHead == nullptr);
}

void StackLL::push(int key)
{
  // 1. empty
  // 2. not empty
  Node* newNode = new Node;
  newNode->key = key;
  newNode->next = stackHead;
  stackHead = newNode;
}

void StackLL::pop()
{
  // stack not empty
  if(!isEmpty())
  {
    Node* tempPtr = stackHead;
    stackHead = stackHead->next;
    delete tempPtr;
  }
  //stack empty
  //else
  //dont do anything,
  // you can print, return error or catch it


}

int StackLL::peek()
{
  if(stackHead == nullptr)
  {
    // error: empty stack
    //throw ValueError;
    return 0;
  }
  return stackHead->key;
}
