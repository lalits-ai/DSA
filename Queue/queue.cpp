#include "queue.h"

bool Queue::isEmpty()
{
  if(front == rear)
    return true;
  return false;
}
bool Queue::isFull()
{
  if(rear == MAX - 1)
    return true;
  return false;
}

void Queue::add(int val)
{
  if(isFull())
    cout<<"Queue overflow!"<<endl;
  else
    q[++rear] = val; 
}

int Queue::del()
{
  if(isEmpty())
  {
    cout<<"Queue underflow!"<<endl;
    return -1;
  }
  else
    return q[++front];
}

int Queue::getFront()
{
  if(isEmpty())
    cout<<"Sorry queue is empty!"<<endl;
  return q[front+1];
}

