#include<iostream>
using namespace std;
const int MAX = 100;

int main()
{
  // Accepting the array dimensions

  int row,col;
  cout<<"Dimensions: "<<endl;
  cout<<"Enter row size: ";
  cin>>row;
  cout<<"Enter column size: ";
  cin>>col;
  int a[row][col];

  // Reading array elements

  cout<<"Enter array elements: "<<endl;
  for(int i=0;i<row;i++)
  {
          for(int j=0;j<col;j++)
                  cin>>a[i][j];
  }

  // Displaying array elemetns

  cout<<"Array elements: "<<endl;
  for(int i=0;i<row;i++)
  {
          for(int j=0;j<col;j++)
                  cout<<a[i][j]<<" ";
          cout<<endl;
  }
  // Mapping to 1D array

  int count = 0;
  int b[MAX];
  for(int i=0;i<col;i++)
  {
    for(int j=0;j<row;j++)
    {
      b[count] = a[j][i];
      count++;
    }
  }

  // Displaying mapped array

  cout<<"Column major order: ";
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
    int offset = (colNum * col) + rowNum;
    if(b[offset] == a[rowNum][colNum])
    {
      cout<<"Value at a["<<rowNum<<"]["<<colNum<<"] is: "<<a[rowNum][colNum]<<endl;
      cout<<"Value at column major order is: "<<b[offset]<<endl;
      cout<<"Value is correctly placed!"<<endl;
    }
    else
      cout<<"Value is not correctly placed or out of bounds"<<endl;
  }
  return 0;
}
