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
    void push(char* val)
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
          cout<<s[temp++]<<endl;
        cout<<endl;
      }
    }
};
Stack palindromeCheck(Stack S)
{
  Stack temp,temp2;
  while(S.getTop() != -1)
  {
    char* data = S.pop();
    int length = 0;
    while(data[length] != '\0')
      length++;
    int j = 0;
    char* reverse = new char[MAX];
    for(int i=length-1;i>=0;i--)
    {
      reverse[j++] = data[i];
    }
    reverse[length] = '\0';
    int palindromeLength = 0;
    for(int i=0;i<length;i++)
    {
      if(reverse[i] == data[i])
        palindromeLength++;
    }
    if(palindromeLength == length)
    {
      char palindrome[] = "Palindrome";
      temp.push(palindrome);
    }
    else
    {
      char notPalindrome[] = "Not Palindrome";
      temp.push(notPalindrome);
    }
  }
  while(temp.getTop() != -1)
  {
    temp2.push(temp.pop());
  }
  return temp2;
}

int main()
{
  int ch;
  char word[MAX];
  Stack original,palindrome;
  do
  {
    cout<<"1. Push word"<<endl;
    cout<<"2. Pop word"<<endl;
    cout<<"3. Display original Stack"<<endl;
    cout<<"4. Display palindrome stack"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter word: ";
              cin>>word;
              original.push(word);
              cout<<"Word pushed successfully!"<<endl;
              break;
      case 2: cout<<"Deleted word: "<<original.pop()<<endl;
              break;
      case 3: cout<<endl;
              original.printStack();
              cout<<endl;
              break;
      case 4: cout<<endl;
              palindrome = palindromeCheck(original);
              palindrome.printStack();
              cout<<endl;
              break;
      case 5: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}