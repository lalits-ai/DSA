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
    void push(float value);
    bool isEmpty();
    bool isFull();
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
  if(op == '+')
    return (op1 + op2);
  else if(op == '-')
    return (op1 - op2);
  else if(op == '*')
    return (op1 * op2);
  else if(op == '/')
  {
    if(op2 == 0)
    {
      cout<<"Division by zero error!"<<endl;
      return 1;
    }
    return (op1 / op2);
  }
  else if(op == '%')
   return ((int)op1 % (int)op2);
  else
    return pow(op1,op2);
}

int main()
{
  cout<<"Enter the postfix expression: ";
  char postfix[50];
  cin.getline(postfix,50);
  cout<<postfix<<endl;
  float result;
  Stack s;
  for(int i=0;postfix[i] != '\0';i++)
  {
    if(isdigit(postfix[i]))
    {
      float num = 0.0;
      while(isdigit(postfix[i]))
      {
        num = num * 10.0 + (int)(postfix[i] - '0');
        i++;
      }
      i--;
      s.push(num);
    }
    else if(postfix[i] == ' ')
      continue;
    else
    {
      float op2 = s.pop();
      float op1 = s.pop();
      char op = postfix[i];
      result = calculate(op1,op,op2);
      s.push(result);
    }
  }
  result = s.pop();
  cout<<"Result: "<<result<<endl;
  return 0;
}