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
    Node* getHead()
    {
      return head;
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
LinkedList intersection(LinkedList l1,LinkedList l2)
{
  bool found = false;
  Node* temp1 = l1.getHead();
  LinkedList intersect;
  while(temp1->link != NULL)
  {
    Node* temp2 = l2.getHead();
    while(temp2->link != NULL)
    {
      temp2 = temp2->link;
      if(temp1->data == temp2->data)
      {
        found = true;
        intersect.insert(temp1->data);
      }
    }
    temp1 = temp1->link;
  }
  if(found)
    return intersect;
  LinkedList emptyList;
  return emptyList;
}
int main()
{
  int ch,val;
  LinkedList l1,l2,intersect;
  do
  {
    cout<<"1. Insert first list"<<endl;
    cout<<"2. Insert second list"<<endl;
    cout<<"3. Display first list"<<endl;
    cout<<"4. Display second list"<<endl;
    cout<<"5. Display intersection list"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>val;
              l1.insert(val);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 2: cout<<"Enter value: ";
              cin>>val;
              l2.insert(val);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 3: cout<<"List contents: \n"<<endl;
              l1.printList();
              cout<<endl;
              break;
      case 4: cout<<"List contents:\n"<<endl;
              l2.printList();
              cout<<endl;
              break;
      case 5: cout<<"Intersection List: \n"<<endl;
              intersect = intersection(l1,l2);
              intersect.printList();
              cout<<endl;
              break;
      case 6: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}