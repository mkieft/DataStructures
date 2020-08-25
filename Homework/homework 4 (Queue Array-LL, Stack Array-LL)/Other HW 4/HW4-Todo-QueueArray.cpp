#include <iostream>
#include "HW4-Todo-QueueArray.hpp"
using namespace std;

TodoQueueArray::TodoQueueArray()
{
  queueFront = -1;
  queueEnd = -1;
}
bool TodoQueueArray::isEmpty()
{
  if(queueFront == -1 && queueEnd == -1)
  {
    return true;
  }
  return false;
}

bool TodoQueueArray::isFull()
{
  if ((queueEnd + 1) % MAX_QUEUE_SIZE == queueFront) {
    return true;
  }
	return false;
}

void TodoQueueArray::enqueue(string todoItem)
{
  if (isFull())
  {
    cout << "Queue full, cannot add new todo item." << endl;
    return;
  }
  if(!isEmpty())
  {
    queueEnd = (queueEnd + 1) % MAX_QUEUE_SIZE;
    TodoItem* nextTodo = new TodoItem;
    nextTodo->todo = todoItem;
    queue[queueEnd] = nextTodo;
  }
  if(isEmpty())
  {
    queueFront = 0;
    queueEnd = 0;
    TodoItem* nextTodo = new TodoItem;
    nextTodo->todo = todoItem;
    queue[queueEnd] = nextTodo;
  }

}
void TodoQueueArray::dequeue()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item." << endl;
    return;
  }
  if(!isEmpty())
  {
    if(queueFront == queueEnd)
    {
      queueEnd = queueFront = -1;
    }
    if (queueFront != queueEnd)
    {
      queueFront = (queueFront + 1) % MAX_QUEUE_SIZE;
    }
  }
}

TodoItem* TodoQueueArray::peek()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot peek." << endl;
    return nullptr;
  }
  return queue[queueFront];
}

int main()
{
  TodoQueueArray test;
  test.enqueue("Laundry");
  cout << test.peek()->todo << endl;
  test.enqueue("Movies");
  cout << test.peek()->todo << endl;
  test.enqueue("Board games");
  cout << test.peek()->todo << endl;
  test.dequeue();
  //test.dequeue();
  cout << test.peek()->todo << endl;
  test.dequeue();
  test.enqueue("Board games");
  test.enqueue("Board games");
  test.enqueue("Board games");
  cout <<test.isFull() << endl;
  test.enqueue("Board games");
  //test.dequeue();
  cout << test.peek()->todo << endl;
  cout <<test.isFull() << endl;
  //cout << test.getQueueFront() << endl << test.getQueueEnd() << endl;

  return 0;
}
