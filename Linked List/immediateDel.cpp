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
  public:
    LinkedList()
    {
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
      }
      else
      {
        Node* temp = head;
        while(temp->link != NULL)
        {
          temp = temp->link;
        }
        newNode->link = NULL;
        temp->link = newNode;
      }
    }
    int remove(int val)
    {
      if(head->link == NULL)
        cout<<"List is empty!"<<endl;
      else
      {
        Node* temp = head->link;
        Node* temp2 = head;
        Node* prev = head;
        bool negative = false;
        if(val < 0)
          negative = true;
        if(negative)
        {
          while(temp->data != val)
          {
            if(temp->data < 0)
              temp2 = temp;
            temp = temp->link;
          }
          while(prev->link != temp2)
          {
            prev = prev->link;
          }
          if(temp2->link == NULL)
            prev->link = NULL;
          else
            prev->link = temp2->link;
          int data = temp2->data;
          delete temp2;
          return data;
        }
        else
        {
          while(temp->data != val)
          {
            if(temp->data >= 0)
              temp2 = temp;
            temp = temp->link;
          }
          while(prev->link != temp2)
          {
            prev = prev->link;
          }
          if(temp2->link == NULL)
            prev->link = NULL;
          else
            prev->link = temp2->link;
          int data = temp2->data;
          delete temp2;
          return data;
        }
      }
      return -1;
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
  LinkedList list;
  int ch,value;
  do
  {
    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>value;
              list.insert(value);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 2: list.printList();
              cout<<"Choose a value to delete: ";
              cin>>value;
              cout<<"\nDeleted value: "<<list.remove(value)<<endl;
              break;
      case 3: cout<<"Stack contents: \n"<<endl;
              list.printList();
              cout<<endl;
              break;
      case 4: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}