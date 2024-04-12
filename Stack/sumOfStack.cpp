#include<iostream>
using namespace std;
const int MAX = 50;
class Stack
{
  int top,s[MAX];
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
        cout<<"Value pushed successfully!"<<endl;
      }
      else
      {
        cout<<"Stack is full!"<<endl;
      }
    }
    int pop()
    {
      int data;
      if(!isEmpty())
      {
        data = s[top--];
        return data;
      }
      else
      {
        cout<<"Stack is empty!"<<endl;
      }
      return -1;
    }
    int getTop()
    {
      return s[top];
    }
    int getSum()
    {
      int sum = 0,poppedVal;
      while(!isEmpty())
      {
        poppedVal = getTop();
        pop();
        sum += poppedVal;
      }
      return sum;
    }
    void printStack()
    {
      int temp = top;
      while(temp != -1)
      {
        cout<<s[temp--]<<" ";
      }
      cout<<endl;
    }
};

int main()
{
  Stack s1,s2;
  int ch,data;
  do
  {
    cout<<"1. Insert value into stack"<<endl;
    cout<<"2. Delete value from stack"<<endl;
    cout<<"3. Display first stack"<<endl;
    cout<<"4. Display second stack"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>data;
              s1.push(data);
              break;
      case 2: cout<<"Value deleted: "<<s1.pop()<<endl;
              break;
      case 3: s1.printStack();
              break;
      case 4: s2.push(s1.getSum());
              cout<<"Contents of second stack: ";
              s2.printStack();
              break;
      case 5: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  }while(true);
  
} 