#include<iostream>
using namespace std;
const int MAX = 10;
class Stack
{
  int top;
  int s[MAX];
  public:
    Stack():top(-1){}
    bool isEmpty()
    {
      return top == -1;
    }
    bool isFull()
    {
      return top == MAX - 1;
    }
    void push(int val)
    {
      if(!isFull())
        s[++top] = val;
    }
    int pop()
    {
      if(!isEmpty())
        return s[top--];
      return -1;
    }
    int findMin()
    {
      int min = s[0];
      for(int i=0;i<MAX;i++)
      {
        if(min > s[i])
          min = s[i];
      }
      return min;
    }
};
int main()
{
  Stack s;
  for(int i=0;i<10;i++)
    s.push(i+1);
  cout<<s.findMin()<<endl;
  return 0;
}