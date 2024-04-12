// Finding middle element of a linked list in one pass

#include "linkedlist.h"

class middleElement : public LinkedList
{
  int length;
  public:
    middleElement()
    {
      length = 0;
      LinkedList();
      Node* head = new Node;
    }
    void findMiddleElement()
    {
      Node* temp = head;
      Node* middle = head;
      while(temp->link != NULL)
      {
        length++;
        if(length%2 == 0)
          middle = middle->link;
        temp = temp->link;
      }
      if(length%2 == 1)
        middle = middle->link;
      cout<<"Middle element: "<<middle->data<<endl;
    }
};

int main()
{
  middleElement M;
  M.insert(34);
  M.insert(56);
  M.insert(43);
  M.insert(98);
  M.findMiddleElement();
  cout<<endl;
  return 0;
}