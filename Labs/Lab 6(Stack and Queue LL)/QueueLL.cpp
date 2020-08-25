#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
  queueFront = nullptr;
  queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

bool QueueLL::isEmpty()
{
    return (queueFront == nullptr);
}

void QueueLL::enqueue(int key)
{
  // create item
  Node* newNode = new Node;
  newNode->key = key;
  newNode->next = nullptr;
  // case 1: empty
  if(isEmpty())
  {
    queueFront = newNode;
    queueEnd = newNode;
  }
  // case 2: not empty
  else
  {
    queueEnd->next = newNode;
    queueEnd = newNode;
  }

}

void QueueLL::dequeue()
{
  // case 1: q empty
  if(isEmpty())
  {
    //error:
    return;
  }
  // case 2: one thing on q
  else if(queueFront == queueEnd)
  {
    delete queueFront;
    queueFront = nullptr;
    queueEnd = nullptr;
  }
  // case 3: > thing
  else
  {
    Node* temp = queueFront;
    queueFront = queueFront->next;
    delete temp;
  }
}

int QueueLL::peek()
{
  if(isEmpty())
  {
    //error case
    return 0;
  }
    return queueFront->key;
}
