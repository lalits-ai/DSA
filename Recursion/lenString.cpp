#include<iostream>
using namespace std;
const int MAX = 100;
int findlen(char* s)
{
  if(*s =='\0')
    return 0;
  else
    return 1+findlen(s+1);
}

bool isPalindrome(char* s,int start,int end)
{
  if(start >= end)
    return true;
  if(s[start] != s[end])
    return false;
  return isPalindrome(s+1,start+1,end-1);
  
}

int main()
{
  char str[MAX];
  cout<<"Enter a string: ";
  cin.getline(str,MAX);
  int len = findlen(str);
  cout<<"Palindrome: "<<isPalindrome(str,0,len-1)<<endl;
  return 0;
}