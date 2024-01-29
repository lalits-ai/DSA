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
void Stack::push(int n)
{
  if(isFull())
    cout<<"Stack is Full"<<endl;
  else
    st[++top] = n;
}
int Stack::pop()
{
  if(isEmpty())
  {
    cout<<"Stack is empty"<<endl;
    return 0;
  }
  else
    return st[bottom++];
}
void Stack::displayStack()
{
  for(int i=0;i<size;i++)
    cout<<st[i]<<" ";
}

