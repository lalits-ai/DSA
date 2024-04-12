#include<iostream>
using namespace std;
const int MAX = 50;
const int colMAX = 50;

class Stack
{
  int top,colTop;
  char s[MAX][colMAX];
  public:
    Stack():top(-1),colTop(-1){}
    bool isEmpty()
    {
      return top == -1;
    }
    bool isFull()
    {
      return top == MAX - 1;
    }
    void push(char val[])
    {
      if(!isFull())
      {
        top++;
        int i=0;
        while(val[i] != '\0')
        {
          s[top][i] = val[i];
          i++;
        }
        s[top][i] = '\0';
        cout<<"Pushed successfully!"<<endl;
      }
      else
      {
        cout<<"Stack overflow!"<<endl;
      }
    }
    const char* pop()
    {
      if(!isEmpty())
      {
        return s[top--];
      }
      else
      {
        cout<<"Stack underflow!"<<endl;
      }
      return "NA";
    }
    const char* getTop()
    {
      return s[top];
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
  int ch;
  char data[MAX];
  Stack S;
  do
  {
    cout<<"1. Push value to stack"<<endl;
    cout<<"2. Pop value from stack"<<endl;
    cout<<"3. Display stack"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter word: ";
              cin>>data;
              S.push(data);
              break;
      case 2: cout<<"Deleted word: "<<S.pop()<<endl;
              break;
      case 3: cout<<"Contents of stack: "<<endl;
              S.printStack();
              break;
      case 4: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  
}