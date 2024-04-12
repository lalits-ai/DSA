#include "stack.h"

bool isOperator(char token)
{
  if(token == '*' || token == '/' || token == '+' ||token == '-' || token == '^')
    return true;
  return false;
}


int precedence(char token)
{
  if(token == '^')
    return 3;
  else if(token == '*' || token == '/')
    return 2;
  else if(token == '+' || token == '-')
    return 1;
  else
    return -1;
}


const int exprMAX = 100;
int main()
{
  Stack s;
  char infix[exprMAX]; // infix character array
  cout<<"Enter the infix expression: ";
  cin>>infix;
  char postfix[exprMAX]; // postfix character array
  int postTrack = 0; // for keeping track of postfix index
  int lenTrack=0,length=0;
  while(infix[lenTrack] != '\0')  // to find the length of infix expr
  {
    length++;
    lenTrack++;
  }
  cout<<"Infix expression: ";
  cout<<infix<<endl;
  cout<<"Length of infix: "<<length<<endl;

  // push '(' onto stack and add ')' onto the infix expr
  s.push('(');
  infix[length] = ')';
  
  // step 2: loop the infix expr

  for(int i=0;i<length+1;i++)
  {
    if(infix[i] == '(') // if '(' occurred
      s.push(infix[i]);
    else if(infix[i] == ')')  // if ')' occurred
    {
      while(!s.isEmpty() && s.getTop() != '(')
      {
        postfix[postTrack++] = s.pop();
      }
      s.pop(); // pop the '('
    }
    else if(infix[i]!='(' && infix[i]!=')' && !isOperator(infix[i]))  // If an operand occurred
    {
      postfix[postTrack++] += infix[i];
    }
    else // if an operator occurred
    {
      while(!s.isEmpty() && precedence(s.getTop()) <= precedence(infix[i]))
      {
        postfix[postTrack++] += s.pop();
      }
      s.push(infix[i]); // Add the operator read
    }
    // s.pop(); // remove the last '(' parenthesis
  }
  while(!s.isEmpty() && s.getTop() != ')')
  {
    postfix[postTrack++] = s.pop();
  }
  cout<<"Postfix expression: "<<postfix<<endl;
  return 0;
}