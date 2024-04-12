#include<iostream>
using namespace std;

class node
{
  public:
    int data;
    node* link;
};
class LinkedList
{
  node* head;
  int count;
  public:
    LinkedList()
    {
      count = 0;
      head->data = count;
      head->link = NULL;
    }
    void insertAtEnd(int data);
    void insertAtBegin(int data);
    void insertAfterNode(int nodeVal,int data);
    int deleteAtBegin();
    int deleteAtEnd();
    int deleteAtNode(int nodeVal);
    int printList();
    void sorted();
};
void LinkedList::sorted()
{
  node* temp = head;
  node* temp2;
  temp = temp->link;
  while(temp->link != NULL)
  {
    temp2 = head;
    while(temp2->link != NULL)
    {
      temp2 = temp2->link;
      if(temp->data < temp2->data)
      {
        node* temp3 = temp;
        temp = temp2;
        temp2 = temp3;
      }
      else
        continue;
    }
    temp = temp->link;
  }
}
void LinkedList::insertAtEnd(int value)
{
  node* newNode = new node;
  newNode->data = value;
  if(head->link == NULL)
  {
    newNode->link = NULL;
    head->link = newNode;
  }
  else
  {
    node* temp = head;
    while(temp->link != NULL)
      temp = temp->link;
    temp->link = newNode;
    newNode->link = NULL;
  }
  sorted();
}
void LinkedList::insertAtBegin(int value)
{
  node* newNode = new node;
  newNode->data = value;
  if(head->link == NULL)
  {
    newNode->link = NULL;
    head->link = newNode;
  }
  else
  {
    newNode->link = head->link;
    head->link = newNode;
  }
  sorted();
}
void LinkedList::insertAfterNode(int nodeVal,int val)
{
  node* newNode = new node;
  newNode->data = val;
  if(head->link == NULL)
  {
    head->link = newNode;
    newNode->link = NULL;
  }
  else
  {
    node* temp = new node;
    temp = head;
    while(temp->data != nodeVal)
    {
      temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
  }
  sorted();
}
int LinkedList::deleteAtBegin()
{
  int data;
  if(head->link == NULL)
  {
    cout<<"List is empty, cannot delete!"<<endl;
    return 0;
  }
  else
  {
    node* temp = head;
    temp = temp->link;
    head->link = temp->link;
    data = temp->data;
    delete temp;
  }
  return data;
}
int LinkedList::deleteAtEnd()
{
  int data;
  if(head->link == NULL)
  {
    cout<<"List is empty, cannot delete!"<<endl;
    return 0;
  }
  else
  {
    node* temp = head;
    node* temp2 = head;
    while(temp->link != NULL)
    {
      temp2 = temp;
      temp = temp->link;
    }
    temp2->link = NULL;
    data = temp->data;
    delete temp;
  }
  return data;
}
int LinkedList::deleteAtNode(int nodeVal)
{
  int data;
  if(head->link == NULL)
  {
    cout<<"Cannot delete! List is empty"<<endl;
    return 0;
  }
  else
  {
    node* temp = head;
    node* temp2 = head;
    while(temp->data != nodeVal)
    {
      temp2 = temp;
      temp = temp->link;
    }
    temp2->link = temp->link;
    data = temp->data;
    delete temp;
  }
  return data;
}
int LinkedList::printList()
{
  if(head->link == NULL)
  {
    cout<<"List is empty!"<<endl;
    return -1;
  }
  else
  {
    node* temp = head;
    while(temp->link != NULL)
    {
      temp = temp->link;
      cout<<temp->data<<" ";
    }
    cout<<endl;
    return 0;
  }
}
int main()
{
  LinkedList list;
  int ch,val,nodeVal=0;
  do
  {
    cout<<"1. Insert at beginning"<<endl;
    cout<<"2. Insert at end"<<endl;
    cout<<"3. Insert after a node"<<endl;
    cout<<"4. Print list"<<endl;
    cout<<"5. Delete at begin"<<endl;
    cout<<"6. Delete at end"<<endl;
    cout<<"7. Delete at a node"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter the value: ";
              cin>>val;
              list.insertAtBegin(val);
              cout<<"Successfull Insertion!"<<endl;
              break;
      case 2: cout<<"Enter the value: ";
              cin>>val;
              list.insertAtEnd(val);
              cout<<"Successfull Insertion"<<endl;
              break;
      case 3: if(list.printList() == -1)
              {
                cout<<"Enter the value to be inserted: ";
                cin>>val;
                list.insertAfterNode(nodeVal,val);
                cout<<"Successfull Insertion"<<endl;
              }
              else
              {
                cout<<"Enter the node value: ";
                cin>>nodeVal;
                cout<<"Enter the value to be inserted: ";
                cin>>val;
                list.insertAfterNode(nodeVal,val);
                cout<<"Successfull Insertion"<<endl;
              }
              break;
      case 4: cout<<"List: ";
              list.printList();
              break;
      case 5: list.printList();
              cout<<"Deleted node: "<<list.deleteAtBegin()<<endl;
              list.printList();
              break;
      case 6: list.printList();
              cout<<"Deleted node: "<<list.deleteAtEnd()<<endl;
              list.printList();
              break;
      case 7: list.printList();
              cout<<"Choose which node to be deleted: ";
              cin>>nodeVal;
              cout<<"Deleted node: "<<list.deleteAtNode(nodeVal)<<endl;
              list.printList();
              break;
      case 8: exit(0);
      default: cout<<"Invalid choice! Try again"<<endl;
               break;
    }
  } while (true); 
  return 0;
}
