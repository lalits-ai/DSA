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
    char* pop()
    {
      if(!isEmpty())
      {
        return s[top--];
      }
      else
        cout<<"Stack underflow"<<endl;
      char* empty;
      return empty;
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
    }
};
Stack convertLowerCase(Stack s1)
{
  Stack temp;
  while(s1.getTop() != -1)
  {
    char* data = s1.pop();
    int i=0;
    while(data[i]!='\0')
    {
      if(data[i]>=65 && data[i]<=90)
        data[i] += 32;
      i++;
    }
    temp.push(data);
  }
  Stack temp2;
  while(temp.getTop() != -1)
  {
    temp2.push(temp.pop());
  }
  return temp2;
}
Stack convertUpperCase(Stack s1)
{
  Stack temp;
  while(s1.getTop() != -1)
  {
    char* data = s1.pop();
    int i = 0;
    while(data[i] != '\0')
    {
      if(data[i] >= 97 && data[i] <= 122)
      {
        data[i] -= 32;
      }
      i++;
    }
    temp.push(data);
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
  Stack original,lower,upper;
  int ch;
  char data[MAX];
  do
  {
    cout<<"1.Insert data"<<endl;
    cout<<"2. Display original Stack"<<endl;
    cout<<"3. Display Lower case stack"<<endl;
    cout<<"4. Display upper case stack"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter data: ";
              cin>>data;
              original.push(data);
              cout<<"Pushed successfully!"<<endl;
              break;
      case 2: cout<<"Orignal stack: \n"<<endl;
              original.printStack();
              cout<<endl;
              break;
      case 3: lower = convertLowerCase(original);
              cout<<"Lower Stack: \n"<<endl;
              lower.printStack();
              cout<<endl;
              break;
      case 4: upper = convertUpperCase(original);
              cout<<"Upper Stack: \n"<<endl;
              upper.printStack();
              cout<<endl;
              break;
      case 5: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}