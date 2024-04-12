#include<iostream>
#include<stack>
using namespace std;

int decToBin(int number)
{
  int rem,count = 0;
  stack<int> s;
  while(number > 0)
  {
    rem = number % 2;
    number /= 2;
    count++;
    s.push(rem);
  }
  int binary=0;
  while(count > 0)
  {
    binary = binary * 10 + s.top();
    s.pop();
    count--;
  }
  return binary;
}
int main()
{
  int decimal;
  cout<<"Enter a decimal number: ";
  cin>>decimal;
  cout<<"Binary representation of "<<decimal<<" is: "<<decToBin(decimal)<<endl;
  return 0;
}
