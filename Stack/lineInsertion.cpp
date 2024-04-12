#include<iostream>
using namespace std;
const int MAX = 100;
const int colMax = 100;

class Stack
{
  int top;
  char s[MAX][colMax];
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
    void push(const char* val)
    {
      if(!isFull())
      {
        top++;
        int length = 0;
        while(val[length] != '\0')
        {
          s[top][length] = val[length];
          length++;
        }
        s[top][length] = '\0';
      }
      else
        cout<<"Stack overflow!"<<endl;
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
      return "-1";
    }
    int getTop()
    {
      return top;
    }
    void printStack()
    {
      if(top == -1)
      {
        cout<<"Stack is empty!"<<endl;
      }
      else
      {
        int temp = 0;
        while(temp <= top)
        {
          cout<<s[temp++]<<endl;
        }
      }
    }
};

Stack reverse(Stack s)
{
  Stack temp,temp2;
  while(s.getTop() != -1)
  {
    int length = 0;
    const char* data = s.pop();
    while(data[length] != '\0')
    {
      length++;
    }
    char* reverse = new char[length];
    int j=0;
    for(int i=length-1;i>=0;i--)
    {
      reverse[j++] = data[i];
    }
    reverse[length] = '\0';
    temp.push(reverse);
  }
  while(temp.getTop() != -1)
  {
    const char* data = temp.pop();
    temp2.push(data);
  }
  return temp2;
}

int main()
{
  Stack s,reversed;
  char data[MAX];
  int ch;
  do
  {
    cout<<"1. Push sentence"<<endl;
    cout<<"2. Pop sentence"<<endl;
    cout<<"3. Display stack"<<endl;
    cout<<"4. Display reverse stack"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter sentence: ";
              cin.ignore();
              cin.getline(data,MAX);
              s.push(data);
              cout<<"Pushed successfully!"<<endl;
              break;
      case 2: cout<<"Deleted sentence: "<<s.pop()<<endl;
              break;
      case 3: cout<<"Stack contents:\n"<<endl;
              s.printStack();
              cout<<endl;
              break;
      case 4: reversed = reverse(s);
              cout<<"Stack contents:\n"<<endl;
              reversed.printStack();
              cout<<endl;
              break;
      case 5: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}