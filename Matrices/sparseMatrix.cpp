#include<iostream>
#include<iomanip>
using namespace std;

struct Sparse
{
  int rowNum,colNum,value;
};

int main()
{
  // Accepting dimensions and elements of sparse matrix

  int count = 0;
  int row,col;
  cout<<"Enter row size: ";
  cin>>row;
  cout<<"Enter column size: ";
  cin>>col;
  int a[row][col];
  cout<<"Enter elements: ";
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      cin>>a[i][j];
      if(a[i][j] != 0)
        count++;
    }
  }

  // Display of sparse Matrix

  cout<<"Sparse Matrix: "<<endl;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }

  // Total non zero elements
  cout<<"No. of non-zero elements: "<<count<<endl;

  // Mapping sparse Matrix to 1D array of triplets

  Sparse s[count];
  int rowTrack = 1; // because s[0] is already there
  int srow = 1; // for s[]

  s[0].rowNum = row;
  s[0].colNum = col;
  s[0].value = count;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(a[i][j] != 0)
      {
        s[srow].rowNum = i;
        rowTrack++;
        s[srow].colNum = j;
        s[srow].value = a[i][j];
        srow++;
      }
    }
  }

  // Displaying the mapped array
  cout<<"Row"<<setw(10)<<"Column"<<setw(10)<<"Value"<<endl;
  cout<<"------------------------------"<<endl;
  for(int i=0;i<rowTrack;i++)
  {
    cout<<s[i].rowNum<<setw(10)<<s[i].colNum<<setw(10)<<s[i].value<<endl;
  }


  // Reconstructing 1D array of triplets to sparse matrix

  int b[row][col];
  int rt = 1;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(s[rt].rowNum == i && s[rt].colNum == j)
        b[i][j] = s[rt++].value;
      else
        b[i][j] = 0;
    }
  }

  cout<<"\nReconstructed array"<<endl;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
      cout<<b[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}