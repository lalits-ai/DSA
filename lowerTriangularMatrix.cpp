#include<iostream>
using namespace std;
const int MAX = 100;

int main()
{
        // Accepting array order

        int order;
        cout<<"Enter array order: ";
        cin>>order;
        int a[order][order];

        // Accepting array elements

        cout<<"Enter array elements: "<<endl;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i < j)
                                a[i][j] = 0;
                        else
                                cin>>a[i][j];
                }
        }

        // displaying lower triangular matrix


        cout<<"Lower triangular matrix elements: "<<endl;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                        cout<<a[i][j]<<" ";
                cout<<endl;
        }
	// Mapping upper triangular to 1D array

        int count = 0;
        int b[MAX];
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i >= j)
                        {
                                b[count] = a[i][j];
                                count++;
                        }
                }
        }

        // Displaying Mapped array elements

        cout<<"Mapped array elements: "<<endl;
        for(int i=0;i<count;i++)
                cout<<b[i]<<" ";
        cout<<endl;

        // Validation

        int rowNum,colNum;
        cout<<"Validation: "<<endl;
        cout<<"Enter any row Number: ";
        cin>>rowNum;
        cout<<"Enter any column number: ";
        cin>>colNum;
        if(rowNum >= colNum)
        {
                int offset = (rowNum * (rowNum + 1)/2 + colNum);
                if(b[offset] == a[rowNum][colNum])
                {
                        cout<<"Value at a["<<rowNum<<"]["<<colNum<<"] is: "<<a[rowNum][colNum]<<endl;
                        cout<<"Value at b["<<offset<<"] is: "<<b[offset]<<endl;
                        cout<<"Value is correctly placed in the mapped array"<<endl;
                }
		else
                {
                        cout<<"Value is not correctly placed"<<endl;
                }
        }
        else
                cout<<"Row number should be greater than Column number or array out of bounds!"<<endl;
        return 0;
}