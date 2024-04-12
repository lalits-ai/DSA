#include<iostream>
using namespace std;

const int MAX = 100;

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
      {
        s[++top] = val;
      }
      else
        cout<<"Stack overflow!"<<endl;
    }
    int pop()
    {
      if(!isEmpty())
        return s[top--];
      cout<<"Stack underflow!"<<endl;
      return -1;
    }
    int getTop()
    {
      return top;
    }
    void printStack()
    {
      int temp = 0;
      while(temp <= top)
      {
        cout<<s[temp++]<<endl;
      }
      cout<<endl;
    }
};
Stack sumTheStack(Stack S)
{
  Stack temp,temp2;
  int singleDigit;
  int data;
  while(S.getTop() != -1)
  {
    int sum = 0;
    data = S.pop();
    while(data > 0)
    {
      singleDigit = data % 10;
      sum += singleDigit;
      data = data/10;
    }
    temp.push(sum);
  }
  while(temp.getTop() != -1)
  {
    temp2.push(temp.pop());
  }
  return temp2;
}
int main()
{
  int ch,data;
  Stack S1,S2;
  do
  {
    cout<<"1. Push value"<<endl;
    cout<<"2. Pop value"<<endl;
    cout<<"3. Display stack"<<endl;
    cout<<"4. Display Sum Stack"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>data;
              S1.push(data);
              cout<<"Pushed successfully!"<<endl;
              break;
      case 2: cout<<"Deleted value: "<<S1.pop()<<endl;
              break;
      case 3: cout<<"Stack contents:\n"<<endl;
              S1.printStack();
              break;
      case 4: S2 = sumTheStack(S1);
              cout<<"Sum Stack contents:\n"<<endl;
              S2.printStack();
              break;
      case 5: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}