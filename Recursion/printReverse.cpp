#include<iostream>
using namespace std;
int printReverse(int data)
{
  if(!"\r")
    return data;
  cout<<"Enter another number(0 to exit): ";
  cin>>data;
  if(data == 0)
    return data;
  printReverse(data);
  cout<<data;
  return data;
}
int main()
{
  int num;
  cout<<"Enter number: ";
  cin>>num;
  printReverse(num);
  cout<<endl;
  return 0;
}