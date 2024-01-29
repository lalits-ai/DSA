#pragma once

#include<iostream>
using namespace std;
const int MAX = 100;
class Stack
{
  int bottom = 0;
  int size;
  int top=-1;
  int st[MAX];
  public:
    Stack(int s):size(s){
    }
    void push(int n);
    int pop();
    bool isFull();
    bool isEmpty();
    void displayStack();
};