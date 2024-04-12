#include "queue.h"

int main()
{
  Queue Q;
  int* data;
  cout<<"Enter 5 data points: "<<endl;
  for(int i=0;i<5;i++)
  {
    cin>>(*data);
    Q.add(*data);
  }
  cout<<"Deleting from Queue order: "<<endl;
  for(int i=0;i<5;i++)
  {
    cout<<Q.del()<<endl;
  }
  return 0;
}