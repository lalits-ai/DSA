#include "Stack.h"

int main()
{
  Stack s;
  for(int i=0;i<10;i++)
    s.push(i+1);
  s.displayStack();
  int arr[10];
  int j=0;
  for(int i=9;i>=0;i--)
  {
    arr[j++] = s.pop();
  }
  cout<<"\nReversed stack: "<<endl;
  for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
  return 0;
}