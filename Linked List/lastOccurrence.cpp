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
        temp->link = newNode;
        newNode->link = NULL;
      }
    }
    int remove(int val)
    {
      if(head->link == NULL)
        cout<<"List is empty!"<<endl;
      else
      {
        bool found = false;
        Node* temp = head;
        Node* temp2 = head;
        Node* prev = head;
        while(temp->link != NULL)
        {
          temp = temp->link;
          if(temp->data == val)
          {
            temp2 = temp;
            found = true;
          }
        }
        if(!found)
        {
          cout<<"Data not found!"<<endl;
        }
        else
        {
          while(prev->link != temp2)
          {
            prev = prev->link;
          }
          int data = temp2->data;
          if(temp2->link == NULL)
          {
            prev->link = NULL;
          }
          else
          {
            prev->link = temp2->link;
          }
          delete temp2;
          return data;
        }
      }
      return -1;
    }
    void printList()
    {
      if(head->link == NULL)
      {
        cout<<"List is empty!"<<endl;
      }
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
    cout<<"1. Insert value"<<endl;
    cout<<"2. Delete value"<<endl;
    cout<<"3. Display list"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>value;
              list.insert(value);
              cout<<"Value inserted!"<<endl;
              break;
      case 2: list.printList();
              cout<<"Choose a value to delete: ";
              cin>>value;
              cout<<"Deleted value: "<<list.remove(value)<<endl;
              break;
      case 3: list.printList();
              break;
      case 4: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}