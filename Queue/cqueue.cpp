#include "queue.h"

bool Queue::isEmpty()
{
  if(front == rear)
    return true;
  return false;
}

bool Queue::isFull()
{
  if(rear == front)
    return true;
  return false;
}

void Queue::add(int val)
{
  if(isEmpty())
  {
    cout<<"Queue is overflowing!"<<endl;
  }
  else
  {
    rear = (rear + 1) % MAX;
    q[rear] = val;
  }
}

int Queue::del()
{
  if(isFull())
  {
    cout<<"Queue is underflowing!"<<endl;
    return -1;
  }
  else
  {
    front = (front + 1) % MAX;
    return q[front];
  }
}
int Queue::getFront()
{
  int temp;
  if(isFull())
    temp = (front + 1) % MAX;
  return q[temp];
}