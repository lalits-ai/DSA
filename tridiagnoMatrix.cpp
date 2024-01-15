#include<iostream>
using namespace std;
const int MAX = 100;

int main()
{
        // Accepting the square matrix order
        int order;
        cout<<"Enter array order: ";
        cin>>order;
        int a[order][order];

        // Accepting the elements
        cout<<"Enter elements: "<<endl;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i==j)
                                cin>>a[i][j];
                        else if(i == j-1)
                                cin>>a[i][j];
                        else if(i == j+1)
                                cin>>a[i][j];
                        else
                                a[i][j] = 0;
                }
        }

        // displaying the tri-diagnol Matrix

        cout<<"Tri-diagnol Matrix elements: "<<endl;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                        cout<<a[i][j]<<" ";
                cout<<endl;
	 }

        // Mapping it into 1D array

        int count = 0, b[MAX];
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i==j)
                        {
                                b[count] = a[i][j];
                                count++;
                        }
                        else if(i == j-1)
                        {
                                b[count] = a[i][j];
                                count++;
                        }
                        else if(i == j+1)
                        {
                                b[count] = a[i][j];
                                count++;
                        }
                }
        }

        // Displaying mapped array elements

        cout<<"Mapped array elements: "<<endl;
        for(int i=0;i<count;i++)
                cout<<b[i]<<" ";
        cout<<endl;

        // Validation

        int offset;
        int rowNum,colNum;
        cout<<"Enter any row number: ";
        cin>>rowNum;
        cout<<"Enter any column number: ";
	cin>>colNum;
        offset = (2 * rowNum) + colNum;
        if(b[offset] == a[rowNum][colNum])
        {
                cout<<"Value at a["<<rowNum<<"]["<<colNum<<"] is: "<<a[rowNum][colNum]<<endl;
                cout<<"Value at mapped array b["<<offset<<"] is: "<<b[offset]<<endl;
                cout<<"Value is correctly placed"<<endl;
        }
        else
                cout<<"Value is not correctly placed or index out of bounds"<<endl;

        return 0;
}
