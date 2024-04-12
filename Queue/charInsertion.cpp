#include<iostream>
using namespace std;
const int MAX = 100;
class Queue
{
  int front,rear;
  char q[MAX][MAX];
  public:
    Queue():front(0),rear(0){}
    bool isEmpty()
    {
      return front == rear;
    }
    bool isFull()
    {
      return rear == MAX - 1;
    }
    void insert(char* val)
    {
      if(!isFull())
      {
        int length = 0;
        while(val[length] != '\0')
        {
          q[rear][length] = val[length];
          length++;
        }
        q[rear][length] = '\0';
        rear++;
      }
      else
        cout<<"Queue overflow!"<<endl;
    }
    const char* remove()
    {
      if(!isEmpty())
      {
        char* deleted = q[front];
        front++;
        return deleted;
      }
      else
        cout<<"Stack underflow!"<<endl;
      const char* empty = "-1";
      return empty;
    }
    void printQueue()
    {
      if(rear == 0)
      {
        cout<<"Queue empty!"<<endl;
      }
      int temp = front;
      while(temp <= rear)
      {
        cout<<q[temp++]<<" ";
      }
      cout<<endl;
    }
    int getRear()
    {
      return rear;
    }
};
int main()
{
  int ch;
  Queue q;
  char data[MAX];
  do
  {
    cout<<"1. Insert value"<<endl;
    cout<<"2. Delete value"<<endl;
    cout<<"3. Display queue"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>data;
              q.insert(data);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 2: cout<<"Deleted value: "<<q.remove()<<endl;
              break;
      case 3: cout<<"Queue contents: \n"<<endl;
              q.printQueue();
              cout<<endl;
              break;
      case 4: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}