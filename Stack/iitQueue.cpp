// Program to showcase basic queue ops
// B Lalit Sai

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	char input[100];
	cout<<"Enter input: ";
	cin.getline(input,100);
	int i=0,len=0;
	while(input[i++] != '\0')
		len++;
	queue<char> q;
	char ch;
	for(int i=0;i<len;i++)
	{
		ch = input[i];
		if(ch == '*')
		{
			cout<<q.front()<<" ";
			q.pop();
		}
		else
			q.push(ch);
	}
	return 0;
}
