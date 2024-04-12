/**Remove Nth Node from End of List:
Given a linked list, remove the nth node from the end of the list and return its head. 
For example, if the list is 1 -> 2 -> 3 -> 4 -> 5 and n = 2, the result should be 1 -> 2 -> 3 -> 5.*/

#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* link;
};
class LinkedList
{
  Node* head;
  int count;
  public:
    LinkedList()
    {
      count = 0;
      head = new Node;
      head->link = NULL;
    }
    void insert(int val)
    {
      Node* newNode = new Node;
      newNode->data = val;
      if(head->link == NULL)
      {
        newNode->link = NULL;
        head->link = newNode;
        ++count;
      }
      else
      {
        Node* temp = head;
        while(temp->link != NULL)
        {
          temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = NULL;
        ++count;
      }
    }
    int remove(int val)
    {
      if(head->link == NULL)
      {
        cout<<"List is empty!"<<endl;
      }
      else
      {
        if(val > count || val < 0)
        {
          cout<<"Invalid node"<<endl;
        }
        else
        {
          Node* temp = head;
          Node* temp2 = head;
          int i = 0;
          while(i <= (count - val) && temp->link != NULL)
          {
            temp2 = temp;
            temp = temp->link;
            i++;
          }
          temp2->link = temp->link;
          int data = temp->data;
          delete temp;
          count--;
          return data;
        }
      }
      return -1;
    }
    int getCount()
    {
      return count;
    }
    void printList()
    {
      if(head->link == NULL)
        cout<<"List is empty!"<<endl;
      else
      {
        Node* temp = head;
        while(temp->link != NULL)
        {
          temp = temp->link;
          cout<<temp->data<<" ";
        }
        cout<<endl;
      }
    }
};
int main()
{
  int ch,value,nodeVal;
  LinkedList list;
  do
  {
    cout<<"1. Insert"<<endl;
    cout<<"2. Remove"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"5. Get count"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>value;
              list.insert(value);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 2: cout<<"Enter the nth node: ";
              cin>>nodeVal;
              cout<<"Before deleting: ";
              list.printList();
              cout<<"Node deleted = "<<list.remove(nodeVal)<<endl;
              cout<<"After deleting: ";
              list.printList();
              break;
      case 3: cout<<"Stack contents:\n"<<endl;
              list.printList();
              cout<<endl;
              break;
      case 4: exit(0);
      case 5: cout<<"The count value is : "<<list.getCount()<<endl;
              break;
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}