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
    int remove()
    {
      int nodeVal,deletedVal;
      printList();
      cout<<"\nEnter node value to delete: ";
      cin>>nodeVal;
      Node* temp = head->link;
      Node* temp2 = head->link;
      bool negative = false;
      if(head == NULL)
      {
        cout<<"List is empty!";
        return -1;
      }
      else
      {
        if(nodeVal < 0)
          negative = true;
        if(negative)
        {
          while(temp->data != nodeVal)
          {
            if(temp->data < 0)
            {
              temp2 = temp;
            }
            temp=temp->link;
          }
          deletedVal = temp2->data;
        }
        else
        {
          while(temp->data != nodeVal)
          {
            if(temp->data > 0)
            {
              temp2 = temp;
            }
            temp = temp->link;
          }
          deletedVal = temp2->data;
        }
        delete temp,temp2;
        return deletedVal;
      }
    }
    void printList()
    {
      Node* temp = head;
      while(temp->link != NULL)
      {
        temp = temp->link;
        cout<<temp->data<<" ";
      }
      cout<<endl;
    }
};


int main()
{
  int ch,value,delVal;
  LinkedList list;
  do
  {
    cout<<"1. Insert value\n2. Delete val\n3. Print List\n4. Exit\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value to insert: ";
              cin>>value;
              list.insert(value);
              break;
      case 2: delVal = list.remove();
              cout<<"Immediate value deleted : "<<delVal<<endl;
              break;
      case 3: cout<<"List contents: "<<endl;
              list.printList();
              break;
      case 4: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  }while(true);
  return 0;  
}