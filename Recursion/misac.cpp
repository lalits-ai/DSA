#include<iostream>
using namespace std;
int fun(int n)
{
  if(n<5)
    return 2*n;
  else
    return 3*fun(n-5)-7;
}
int main()
{
  cout<<"fun(10): "<<fun(10)<<endl;
  cout<<"fun(12): "<<fun(12)<<endl;
  return 0;
}