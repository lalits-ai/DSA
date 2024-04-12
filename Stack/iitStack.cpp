// Program to showcase the usage of push and pop ops

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<char> s;
	char input[100];
	cout<<"Enter input: ";
	cin.getline(input,100);
	int i=0,len = 0;
	while(input[i++] != '\0')
		len++;
	char ch;
	for(int i=0;i<len;i++)
	{
		ch = input[i];
		if(ch == '*')
		{
			cout<<s.top();
			s.pop();
		}
		else
			s.push(ch);
	}
	return 0;
}

