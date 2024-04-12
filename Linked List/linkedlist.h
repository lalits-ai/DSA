#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* link;
};
class LinkedList
{
  public:
    Node* head;
    LinkedList();
    void insert(int val);
    int remove();
    int displayList();
};

