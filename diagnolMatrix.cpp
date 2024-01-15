#include<iostream>
using namespace std;
const int MAX = 100;

int main()
{
        // Accepting the square matrix order
        int order;
        cout<<"Enter array order: ";
        cin>>order;

        // Accepting square matrix elements

        cout<<"Enter array elements: "<<endl;
        int a[order][order];
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i == j)
                                cin>>a[i][j];
                        else
                                a[i][j] = 0;
                }
        }

        // Displaying the diagnol matrix

        cout<<"Diagnol matrix: "<<endl;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                        cout<<a[i][j]<<" ";
                cout<<endl;
        }
	// Mapping diagnol matrix to 1D array

        int b[MAX], count = 0;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i == j)
                        {
                                b[count] = a[i][j];
                                count++;
                        }
                }
        }

        // Displaying mapped array

        cout<<"Mapped array: "<<endl;
        for(int i=0;i<count;i++)
                cout<<b[i]<<" ";
        cout<<endl;

        // Checking for index values

        cout<<"Diagnol matrix index values : "<<endl;
        for(int i=0;i<order;i++)
        {
                for(int j=0;j<order;j++)
                {
                        if(i==j)
                                cout<<"a["<<i<<"]["<<j<<"]"<<endl;
                }
        }

        // Validation

        int rowNum;
        cout<<"Enter any index value to check for validation: ";
        cin>>rowNum;
        if(b[rowNum] == a[rowNum][rowNum])
	{
                cout<<"Value at a["<<rowNum<<"]["<<rowNum<<"] is : "<<a[rowNum][rowNum]<<endl;
                cout<<"Value at mapped order b["<<rowNum<<"] is: "<<b[rowNum]<<endl;
                cout<<"Value is correctly placed"<<endl;
        }
        else
                cout<<"Value is not correctly placed or rowNum out of bounds"<<endl;

        return 0;
}