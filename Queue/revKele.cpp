// Program to reverse k elements of a queue in reverse order and leaving the rest other elements just like that
#include<iostream>
using namespace std;
const int MAX = 10;
class Queue
{
  int q[MAX];
  int front,rear;
  int count;
  public:
    Queue():front(-1),rear(-1),count(-1){}
    bool isEmpty()
    {
      return rear == -1;
    }
    bool isFull()
    {
      return front == MAX - 1;
    }
    void enqueue(int val)
    {
      if(!isFull())
      {
        q[++rear] = val;
      }
      else
        cout<<"Queue is full!"<<endl;
    }
    int dequeue()
    {
      if(!isEmpty())
        return q[++front];
      else
        cout<<"Queue is empty!"<<endl;
      return -1;
    }
    int getFront()
    {
      return q[front];
    }
    void resetVar()
    {
      rear = -1;
      front = -1;
    }
    void display(int len)
    {
      for(int i=0;i<len;i++)
        cout<<q[i]<<" ";
    }
};
class Stack
{
  int s[MAX];
  int top;
  public:
    Stack():top(-1){}
    bool isEmpty()
    {
      return top == -1;
    }
    bool isFull()
    {
      return top == MAX - 1;
    }
    void push(int val)
    {
      if(!isFull())
        s[++top] = val;
    }
    int pop()
    {
      if(!isEmpty())
        return s[top--];
      return -1;
    }
    int getTop()
    {
      return s[top];
    }
};
int main()
{
  int n;
  cout<<"Enter number of elements to enter into queue: ";
  cin>>n;
  Queue q;
  for(int i=0;i<n;i++)
    q.enqueue(i+1);
  cout<<"Enter k: ";
  int k;
  cin>>k;
  Stack s;
  int delVal;
  for(int i=0;i<k;i++)
  {
    delVal = q.dequeue();
    s.push(delVal);
  }
  q.resetVar();
  int pop;
  for(int i=0;i<k;i++)
  {
    pop = s.pop();
    q.enqueue(pop);
  }
  q.display(n);
  return 0;
}