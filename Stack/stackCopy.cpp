#include "stack.h"

void copyStack(Stack src,int size)
{
  Stack dest;
  Stack temp;
  for(int i=0;i<size;i++)
  {
    temp.push(src.pop());
  }
  for(int i=0;i<size;i++)
    dest.push(temp.pop());
  cout<<"Copied stack: "<<endl;
  dest.displayStack();
}
int main()
{
  Stack src;
  cout<<"Enter the size of the stack: ";
  int length;
  cin>>length;
  for(int i=0;i<length;i++)
  {
    char data;
    cin.ignore();
    cout<<"Enter data: ";
    cin>>data;
    src.push(data);
  }
  cout<<"Original stack: "<<endl;
  src.displayStack();
  copyStack(src,length);
  return 0;
}