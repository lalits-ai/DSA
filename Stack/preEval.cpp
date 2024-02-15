#include<iostream>
#include<cmath>
using namespace std;

const int MAX = 100;
class Stack
{
  float s[MAX];
  int top;
  public:
    Stack():top(-1){}
    bool isEmpty();
    bool isFull();
    void push(float value);
    float pop();
};
bool Stack::isEmpty()
{
  return top == -1;
}
bool Stack::isFull()
{
  return top == MAX - 1;
}
void Stack::push(float value)
{
  if(!isFull())
    s[++top] = value;
}
float Stack::pop()
{
  if(!isEmpty())
    return s[top--];
  return -1;
}

float calculate(float op1,char op,float op2)
{
  if(op == '*')
    return op1 * op2;
  else if(op == '+')
    return op1 + op2;
  else if(op == '-')
    return op1 - op2;
  else if(op == '^')
    return (pow(op1,op2));
  else if(op == '/')
  {
    if(op2 == 0)
    {
      cout<<"Division by zero error!"<<endl;
      return 1;
    }
    return op1 / op2;
  }
  else
    return (int)op1 % (int)op2;
}

int main()
{
  char prefix[50],ch;
  char pre[50];
  float result;
  cout<<"Enter the prefix expression: ";
  cin.getline(prefix,50);
  Stack s;
  cout<<prefix<<endl;
  int i=0,length=0; // To keep track of prefix expr length
  while(prefix[i++]!='\0')
  {
    length++;
  }
  for(int i=length-1;i>=0;i--) // scan from right to left
  {
    if(isdigit(prefix[i]))
    {
      float j = i;
      float num = 0;
      while(isdigit(prefix[i]))
      {
        i--;
      }
      i++;
      for(int k=i;k<=j;k++)
      {
        num = num*10 + (float)(prefix[k]-'0');
      }
      s.push(num);
    }
    else if(prefix[i] == ' ')
      continue;
    else
    {
      float op1 = s.pop();
      cout<<op1<<endl;
      float op2 = s.pop();
      cout<<op2<<endl;
      char op = prefix[i];
      result = calculate(op1,op,op2);
      s.push(result);
    }
  }
  result = s.pop();
  cout<<"Result: "<<result<<endl;
  return 0;
}