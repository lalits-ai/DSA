#include<iostream>
using namespace std;

const int MAX = 100;
const int colMAX = 100;

class Stack
{
  int top;
  char s[MAX][colMAX];
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
    void push(const char* str)
    {
      if(!isFull())
      {
        top++;
        int length = 0;
        while(str[length] != '\0')
        {
          s[top][length] = str[length];
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
        return s[top--];
      cout<<"Stack underflow!"<<endl;
      return "-1";
    }
    int getTop()
    {
      return top;
    }
    void printStack()
    {
      int temp = 0;
      if(top == -1)
        cout<<"Stack is empty!"<<endl;
      else
      {
        while(temp <= top)
        {
          cout<<s[temp++]<<endl;
        }
        cout<<endl;
      }
    }
};
Stack reverse(Stack S)
{
  Stack temp;
  while(S.getTop() != -1)
  {
    const char* data = S.pop();
    int length = 0;
    int j = 0;
    while(data[length] != '\0')
    {
      length++;
    }
    char* reverse = new char[length];
    for(int i=length-1;i>=0;i--)
    {
      reverse[j++] = data[i];
    }
    reverse[length] = '\0';
    temp.push(reverse);
  }
  Stack temp2;
  while(temp.getTop() != -1)
  {
    temp2.push(temp.pop());
  }
  return temp2;
}
int main()
{
  Stack s1,s2;
  int ch;
  char data[MAX];
  do
  {
    cout<<"1. Push value"<<endl;
    cout<<"2. Pop value"<<endl;
    cout<<"3. Dispaly stack"<<endl;
    cout<<"4. Display Reverse stack"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter word: ";
              cin>>data;
              s1.push(data);
              cout<<"Word pushed successfully!"<<endl;
              break;
      case 2: cout<<"Deleted word: "<<s1.pop()<<endl;
              break;
      case 3: cout<<"Stack contents:\n"<<endl;
              s1.printStack();
              break;
      case 4: s2 = reverse(s1);
              cout<<"Stack contents:\n"<<endl;
              s2.printStack();
              break;
      case 5: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}