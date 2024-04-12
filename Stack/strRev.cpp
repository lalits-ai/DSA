#include "stack.h"
#include<string>

string reverse(string str)
{
  string temp;
  Stack s;
  for(int i=0;i<str.length();i++)
    s.push(str[i]);
  while(!s.isEmpty())
    temp += s.pop();
  return temp;
}

int main()
{
  int length=0;
  cout<<"Enter a string: ";
  string s;
  getline(cin,s);
  string reversed = reverse(s);
  cout<<"Reversed string: "<<reversed<<endl;
  return 0;
}