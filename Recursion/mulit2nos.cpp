#include<iostream>
using namespace std;

int mul(int a,int b)
{
  if(a<b)
    return mul(b,a);
  else if(b!=0)
    return (a+mul(a,b-1));
  else
    return 0;
}
int main()
{
  int num1,num2;
  cout<<"Enter number 1: ";
  cin>>num1;
  cout<<"Enter number 2: ";
  cin>>num2;
  int result = mul(num1,num2);
  cout<<"Product of two numbers: "<<result<<endl;
  return 0;
}