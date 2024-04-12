#include<iostream>
using namespace std;
const int MAX = 7;
class Queue
{
  int q[MAX];
  int front,rear;
  public:
    Queue():front(-1),rear(-1){}
    void add(int value);
    int del();
    int getFront();
    bool isEmpty();
    bool isFull();
};