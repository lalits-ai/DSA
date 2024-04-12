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
      else
        cout<<"Stack underflow!"<<endl;
      return -1;
    }
    int getTop()
    {
      return top;
    }
    void printStack()
    {
      if(top == -1)
        cout<<"Stack is empty!"<<endl;
      else
      {
        int temp = 0;
        while(temp <= top)
        {
          cout<<s[temp++]<<" ";
        }
        cout<<endl;
      }
    }
};
Stack merge(Stack S1,Stack S2)
{
  Stack temp,temp2;
  while(S1.getTop() != -1)
  {
    temp.push(S1.pop());
  }
  while(S2.getTop() != -1)
  {
    temp.push(S2.pop());
  }
  while(temp.getTop() != -1)
  {
    temp2.push(temp.pop());
  }
  return temp2;
}
int main()
{
  int ch,data,stack;
  Stack first,second,merged;
  do
  {
    cout<<"1. First stack push"<<endl;
    cout<<"2. First stack pop"<<endl;
    cout<<"3. First stack display"<<endl;
    cout<<"4. Second stack push"<<endl;
    cout<<"5. Second stack pop"<<endl;
    cout<<"6. Second stack display"<<endl;
    cout<<"7. Merged stack display"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>data;
              first.push(data);
              cout<<"Pushed successfully!"<<endl;
              break;
      case 2: cout<<"Deleted value: "<<first.pop()<<endl;
              break;
      case 3: cout<<"Stack contents:\n"<<endl;
              first.printStack();
              cout<<endl;
              break;
      case 4: cout<<"Enter value: ";
              cin>>data;
              second.push(data);
              cout<<"Pushed successfully!"<<endl;
              break;
      case 5: cout<<"Deleted value: "<<second.pop()<<endl;
              break;
      case 6: cout<<"Stack contents:\n"<<endl;
              second.printStack();
              cout<<endl;
              break;
      case 7: merged = merge(first,second);
              cout<<"Merged stack contents:\n"<<endl;
              merged.printStack();
              cout<<endl;
              break;
      case 8: exit(0);
      default: cout<<"Invalid choice!"<<endl;
    }
  } while (true);
  return 0;
}