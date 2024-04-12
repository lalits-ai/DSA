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
        if(temp->link == NULL)
        {
          temp->link = newNode;
          newNode->link = NULL;
        }
        else
        {
          newNode->link = temp->link;
          temp->link = newNode;
        }
      }
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
    Node* getHead()
    {
      return head;
    }
};

LinkedList merge(LinkedList l1,LinkedList l2)
{
  Node* head1 = l1.getHead();
  Node* head2 = l2.getHead();
  Node* temp = head1;
  LinkedList mergedList;
  while(temp->link != NULL)
  {
    temp = temp->link;
    mergedList.insert(temp->data);
  }
  temp = head2;
  while(temp->link != NULL)
  {
    temp = temp->link;
    mergedList.insert(temp->data);
  }
  return mergedList;
}

int main()
{
  int ch,value;
  LinkedList list1,list2,mergedList;
  do
  {
    cout<<"1. Insert into first list"<<endl;
    cout<<"2. Display first list"<<endl;
    cout<<"3. Insert into second list"<<endl;
    cout<<"4. Display second list"<<endl;
    cout<<"5. Display merged list"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter value: ";
              cin>>value;
              list1.insert(value);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 2: cout<<"List contents:\n"<<endl;
              list1.printList();
              cout<<endl;
              break;
      case 3: cout<<"Enter value: ";
              cin>>value;
              list2.insert(value);
              cout<<"Inserted successfully!"<<endl;
              break;
      case 4: cout<<"List contents:\n"<<endl;
              list2.printList();
              cout<<endl;
              break;
      case 5: mergedList = merge(list1,list2);
              cout<<"List contents:\n"<<endl;
              mergedList.printList();
              cout<<endl;
              break;
      case 6: exit(0);
      default: cout<<"Invalid choice!"<<endl;
               break;
    }
  } while (true);
  return 0;
}