#include<iostream>
using namespace std;

struct node
{
  static int count;
  int data;
  node* next;
};
int node::count = -1;
int main()
{
  node* head = new node;
  node* node1 = new node;
  head->next = node1;

  // Insertion at the beginning

  node1 -> data = 10;
  node1 -> next = nullptr;

  node* node2 = new node;
  node2->data = 20;
  node1->next = node2;
  node2->next = nullptr;

  node* node3 = new node;
  node3->data = 30;
  node2->next = node3;
  node3->next = nullptr;

  // Now we have 10,20,30 as the list
  // Insertion at the beginning

  node* newNode = new node;
  newNode->next = head->next;
  head->next = newNode;
  newNode->data = 0;

  head->data = node::count;

  cout<<newNode->data<<endl;
  cout<<node1->data<<endl;
  cout<<node2->data<<endl;
  cout<<node3->data<<endl;
  cout<<"Total count: "<<head->data<<endl;

  return 0;
}
