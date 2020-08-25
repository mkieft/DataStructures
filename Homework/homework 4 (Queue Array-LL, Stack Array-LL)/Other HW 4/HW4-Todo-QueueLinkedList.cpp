#include <iostream>
using namespace std;
#include "HW4-Todo-QueueLinkedList.hpp"

TodoQueueLinkedList::TodoQueueLinkedList()
{
  queueFront = nullptr;
  queueEnd = nullptr;
}

TodoQueueLinkedList::~TodoQueueLinkedList()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

bool TodoQueueLinkedList::isEmpty()
{
    return (queueFront == nullptr);
}

void TodoQueueLinkedList::enqueue(string todoItem)
{
  // create item
  TodoItem *next = new TodoItem;
  next->todo = todoItem;
  next->next = nullptr;

  if(!isEmpty())
  {
    queueEnd->next = next;
    queueEnd = next;
  }

  if(isEmpty())
  {
    queueFront = next;
    queueEnd = next;
  }

}
void TodoQueueLinkedList::dequeue()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item." << endl;
  }
  if(!isEmpty())
  {
    if(queueFront == queueEnd)
    {
      delete queueFront;
      queueFront = nullptr;
      queueEnd = nullptr;
    }
    if(queueFront != queueEnd)
    {
      TodoItem* temp = queueFront;
      queueFront = queueFront->next;
      delete temp;
    }

  }
}


TodoItem* TodoQueueLinkedList::peek()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot peek." << endl;
  }
  return queueFront;
}

int main()
{
    TodoQueueLinkedList emptyList;
    cout<<(emptyList.isEmpty() ) << endl;
    emptyList.enqueue("Laundry");
    cout << emptyList.peek()->todo << endl;
    emptyList.enqueue("abc");
    cout << emptyList.peek()->todo << endl;
    emptyList.enqueue("Movies");
    cout << emptyList.peek()->todo << endl;
    cout << emptyList.getQueueFront()->todo << endl;
    cout << emptyList.getQueueEnd()->todo << endl;
    cout << emptyList.peek()->todo << endl;
    delete emptyList;


    return 0;
}
