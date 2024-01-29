/*Rahul and Ritika are playing a game of stacks where each of them are having a stack A and B
of integers. Rahul gives a random integer X to Ritika and tells her about the rules of the game which are:-
In each move, Ritika can remove one integer from the top of either stack A or stack B.
Ritika keeps a running sum of the integers she removes from the two stacks.
Ritika is disqualified from the game if, at any point, her running sum becomes greater than some integer X given at the beginning of the game.
Ritika's final score is the total number of integers she has removed from the two stacks.

Find the maximum possible score Ritika can achieve during each game and print it*/


#include "stack.h"

int main()
{
  cout<<"Enter the size of first stack: ";
  int size1,size2;
  cin>>size1;
  cout<<"Enter the size of the second stack: ";
  cin>>size2;
  Stack A(size1),B(size2);
  cout<<"Enter the 1st stack elements: "<<endl;
  for(int i=0;i<size1;i++)
  {
    int data;
    cin>>data;
    A.push(data);
  }
  cout<<"Enter the 2nd stack elements: "<<endl;
  for(int i=0;i<size2;i++)
  {
    int data;
    cin>>data;
    B.push(data);
  }
  cout<<"Enter the no. of games to be played: ";
  int T;
  cin>>T;
  for(int i=0;i<T;i++) // Games loop
  {
    int sum=0; // running sum
    int move = 0;
    int currentStack = 0;
    cout<<"Enter the number: ";
    int x;
    cin>>x;
    while(sum < x && !A.isEmpty() && !B.isEmpty())
    {
      move++;
      if(currentStack == 0 && !A.isEmpty())
      {
        int *poppedData =  new int(A.pop());
        sum += (*poppedData);
        if(sum >= x)
          move--;
        delete poppedData;
        currentStack = 1;
      }
      else
      {
        int *poppedData = new int(B.pop());
        sum += (*poppedData);
        if(sum >= x)
          move--;
        delete poppedData;
        currentStack = 0;
      }
    }
    cout<<"Total moves: "<<move<<endl;
  }
}
