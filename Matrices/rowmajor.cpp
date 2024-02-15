#include<iostream>
using namespace std;
const int MAX = 100;

int main()
{
  int row,col;

  // Accepting dimensions

  cout<<"Dimensions: "<<endl;
  cout<<"Enter row size: ";
  cin>>row;
  cout<<"Enter column size: ";
  cin>>col;
  int a[row][col];
  int b[MAX];

  // Reading matrix elements

  cout<<"Enter elements: "<<endl;
  for(int i=0;i<row;i++)
  {
          for(int j=0;j<col;j++)
                  cin>>a[i][j];
  }

  // Displaying matrix elements

  cout<<"Array elements are : "<<endl;
  for(int i=0;i<row;i++)
  {
          for(int j=0;j<col;j++)
                  cout<<a[i][j]<<" ";
          cout<<endl;
  }
  
  // Mapping to 1D array

  int count = 0;
  for(int i=0;i<row;i++)
  {
          for(int j=0;j<col;j++)
          {
                  b[count] = a[i][j];
                  count++;
          }
  }

  // Displaying mapped array elements

  cout<<"Mapped array elements: "<<endl;
  for(int i=0;i<count;i++)
          cout<<b[i]<<" ";
  cout<<endl;

  // Validation

  if(row == col)
  {
          cout<<"Validation: "<<endl;
          int rowNum,colNum;
          cout<<"Enter any row number: ";
          cin>>rowNum;
          cout<<"Enter any column number: ";
          cin>>colNum;
          int offset = (rowNum * row) + colNum;
          if(b[offset] == a[rowNum][colNum])
          {
                  cout<<"Value at a["<<rowNum<<"]["<<colNum<<"] is: "<<a[rowNum][colNum]<<endl;
                  cout<<"Value at b["<<offset<<"] is: "<<b[offset]<<endl;
                  cout<<"Value is correctly placed in the row major matrix"<<endl;
          }
          else
                  cout<<"Value is not correctly placed or out of bounds"<<endl;
  }
  return 0;
}