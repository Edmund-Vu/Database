#include "ListNode.h"
#include <iostream>

using namespace std;

template <class T>
class NaiveList{
  public:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

    NaiveList();
    ~NaiveList();
    void insertFront(T d);
    T removeFront();
    T removeBack();
    T deletePos(int pos);
    int find(T val);
    void printList();
    unsigned int getSize();
};
