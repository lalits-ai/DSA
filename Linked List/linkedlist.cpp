#include "linkedlist.h"

LinkedList::LinkedList()
{
  head->link = NULL;
}
void LinkedList::insert(int val)
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
      temp = temp->link;
    temp->link = newNode;
    newNode->link = NULL;
  }
}
int LinkedList::remove()
{
  int data;
  if(head->link == NULL)
  {
    cout<<"List is empty, cannot delete!"<<endl;
    return 0;
  }
  else
  {
    Node* temp = head;
    Node* temp2 = head;
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
int LinkedList::displayList()
{
  if(head->link == NULL)
  {
    cout<<"List is empty!"<<endl;
    return -1;
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
    return 0;
  }
}
