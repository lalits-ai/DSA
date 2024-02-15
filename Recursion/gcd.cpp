#include<iostream>
using namespace std;
int gcd(int a,int b)
{
  if(a == 0)
    return b;
  else if(b == 0)
    return a;
  else
    return gcd(b,a%b);
}
int main()
{
  int num1,num2;
  cout<<"Enter first number: ";
  cin>>num1;
  cout<<"Enter second number: ";
  cin>>num2;
  cout<<gcd(num1,num2)<<endl;
  return 0;
}