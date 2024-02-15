#include<iostream>
using namespace std;
int fib(int n)
{
  if(n == 0 || n == 1)
    return n;
  else
    return (fib(n-1)+fib(n-2));
}
int main()
{
  int number;
  cout<<"Enter number: ";
  cin>>number;
  for(int i=0;i<number;i++)
    cout<<fib(i)<<" ";
  return 0;
}