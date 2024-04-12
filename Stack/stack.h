#pragma once

#include<iostream>
using namespace std;
const int MAX = 100;
class Stack
{
  int top;
  char st[MAX];

  public:
    Stack():top(-1){}
    void push(char ch);
    char pop();
    bool isFull();
    bool isEmpty();
    int getTop();
    void displayStack();
};