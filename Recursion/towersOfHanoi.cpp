#include<iostream>
using namespace std;
void towers(int n,string src,string dest,string aux)
{
  // case 1: one disk
  if(n==1)
    cout<<"Move disk from "<<src<<" -> "<<dest<<endl;
  // case 2: Two disks
  if(n==2)
  {
    cout<<"Move disk from "<<src<<" -> "<<aux<<endl;
    cout<<"Move disk from "<<src<<" -> "<<dest<<endl;
    cout<<"Move disk from "<<aux<<" -> "<<dest<<endl;
  }
  if(n>=3)
  {
    towers(n-1,src,aux,dest);
    cout<<"Move disk from "<<src<<" -> "<<dest<<endl;
    towers(n-1,aux,dest,src);
  }
}
int main()
{
  int disks;
  cout<<"Enter number of disks: ";
  cin>>disks;
  towers(disks,"A","C","B");
  return 0;
}