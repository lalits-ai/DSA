// Program to parse the delimiters
#include "stack.h"

bool bracketCheck(char expr[],int size)
{
  Stack s;
  for(int i=0;i<size;i++)
  {
    char c = expr[i];
    if(c=='('||c=='{'||c=='[')
      s.push(c);
    else if((s.getTop()=='(' && c==')')|| (s.getTop()=='{' && c=='}') || 
            (s.getTop()=='[' && c==']'))
            s.pop();
    else
      continue;
  }
  if(s.isEmpty())
    return true;
  return false;
}
int main()
{
  char expr[50];
  cout<<"Enter expression: ";
  cin>>expr;
  int length = 0,i=0;
  while(expr[i++]!='\0')
    length++;
  if(bracketCheck(expr,length))
    cout<<"Brackets aligned perfectly!"<<endl;
  else
    cout<<"Brackets alignment error!"<<endl;
  return 0;
}