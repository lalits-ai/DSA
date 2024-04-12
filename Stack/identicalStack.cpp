#include<iostream>
using namespace std;
class Stack
{
  int top;
  int s[10];
  public:
    Stack():top(-1){}
    void push(int value)
    {
      s[++top] = value;
    }
    int pop()
    {
      return s[top--];
    }
    
};
void checkIdentical(Stack s1,Stack s2)
{
  int data1,data2,count = 0;
  for(int i=0;i<5;i++)
  {
    data1 = s1.pop();
    data2 = s2.pop();
    if(data1 == data2)
      count++;
  }
  if(count == 5)
    cout<<"Stacks are identical"<<endl;
  else
    cout<<"Stacks are not identical"<<endl;
}
int main()
{
  Stack s1,s2;
  int data;
  cout<<"Enter the stack 1 values: ";
  for(int i=0;i<5;i++)
  {
    cin>>data;
    s1.push(data);
  }
  cout<<"Enter the stack 2 values: ";
  for(int i=0;i<5;i++)
  {
    cin>>data;
    s2.push(data);
  }
  checkIdentical(s1,s2);
  return 0;
}