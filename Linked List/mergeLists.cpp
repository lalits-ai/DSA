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
        while(temp->link != NULL && temp->link->data < val)
        {
          temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
      }
    }
    LinkedList merge(LinkedList list1,LinkedList list2)
    {
      LinkedList list3;
      
    }
};