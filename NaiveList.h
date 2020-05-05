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
    ListNode<T> remove(T key);
};

template <class T>
NaiveList<T>::NaiveList(){
  back = NULL;
  front = NULL;
  size = 0;
}

template <class T>
NaiveList<T>::~NaiveList(){

}

template <class T>
void NaiveList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0){
    back = node;
  } else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

template <class T>
T NaiveList<T>::removeFront(){
  ListNode<T> *temp = front;
  if(front->next == NULL){
    back = NULL;
  } else{
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  T data = temp->data;
  delete temp;
  size--;
  return data;
}

template <class T>
T NaiveList<T>::removeBack(){
  ListNode<T> *temp = back;
  if(back->prev == NULL){
    front = NULL;
  } else{
    back->prev->next = NULL;
  }
  back = back->prev;
  temp->prev = NULL;
  T data = temp->data;
  delete temp;
  size--;
  return data;
}

template <class T>
T NaiveList<T>::deletePos(int pos){
  --size;
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    ++idx;
  }

  prev->next = curr->next;
  curr->next = NULL;
  T d = curr->data;
  delete curr;
  return d;
}

template <class T>
int NaiveList<T>::find(T val){
  int idx = -1;
  ListNode<T> *curr = front;
  while(curr != NULL){
    ++idx;
    if(curr->data = val){
      break;
    } else{
      curr = curr->next;
    }
  }
  if(curr == NULL){
    idx = -1;
  }
  return idx;
}

template <class T>
void NaiveList<T>::printList(){
  ListNode<T> *curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
unsigned int NaiveList<T>::getSize(){
  return size;
}

template <class T>
ListNode<T>* NaiveList<T>::remove(T key){
  ListNode<T>* curr = front;
  while(curr->data != key){
    curr = curr->next;
    if(curr == NULL){
      return NULL;
    }
  }
  if(curr == front){
    front = curr->next;
  } else{
    curr->prev->next = current->next;
  }
  if(curr == back){
    back = curr->prev;
  } else{
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  --size;
  return curr;
}
