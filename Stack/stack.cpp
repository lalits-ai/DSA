#include "stack.h"

bool Stack::isFull()
{
  if(top>=MAX)
    return true;
  return false;
}
bool Stack::isEmpty()
{
  if(top==-1)
    return true;
  return false;
}
void Stack::push(char ch)
{
  if(isFull())
    cout<<"Stack is Full"<<endl;
  else
  {
    st[++top] = ch;
    size++;
  }
}
char Stack::pop()
{
  if(isEmpty())
  {
    cout<<"Stack is empty"<<endl;
    return '0';
  }
  else
  {
    size--;
    return st[top--];
  }
}
int Stack::getTop()
{
  return st[top];
}

