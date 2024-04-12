#include<iostream>
using namespace std;

int main()
{
  int* ptr = new int;
  *ptr = 45;
  cout<<*ptr<<endl;
  delete ptr;
  char* chptr = NULL;
  chptr = new char[10];
  cout<<"Enter name: ";
  cin.getline(chptr,10);
  for(int i=0;i<10;i++)
  {
    cout<<chptr[i];
  }
  cout<<endl;
  
  delete[] chptr;
  return 0;
}