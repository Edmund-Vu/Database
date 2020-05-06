#include "TreeNode.h"
#include <iostream>
#include <fstream>

template <class T>
class BST{
  public:
    BST();
    virtual ~BST();

    void insert(T val);
    bool contains(T val);
    bool deleteRec(T k);
    bool isEmpty();
    T search(T val);
    void printTree();
    void recPrint(TreeNode<T> *node);
    TreeNode<T>* getSucc(Treenode<T> *d);
    void treeToFile(ofstream& file);
    void treeToFile(TreeNode<T>* root, ofstream& file);
  private:
    TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
  root = NULL;
}

template <class T>
BST<T>::~BST(){
  while(root != NULL){
    deleteRec(root->key);
  }
}

template <class T>
void BST<T>::insert(T val){
  TreeNode<T> *node = new TreeNode<T>(val);

  if(isEmpty()){
    root = node;
  } else{
    TreeNode<T>* curr = root;
    TreeNode<T>* parent;
    while(true){
      parent = current;
      if(val < curr->key){
        curr = curr->left;
        if(cuff == NULL){
          parent->left = node;
          break;
        }
      } else{
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::contains(T val){
  if(root == NULL){
    return false;
  } else{
    TreeNode<T> *curr = root;
    while(curr->key != val){
      if(curr == NULL){
        return false;
      }
      if(val < curr->key){
        curr = curr->left;
      } else{
        curr = curr->right;
      }
    }
    return true;
  }
}

template <class T>
bool BST<T>::deleteRec(T k){
  if(!contains(k)){
    return false;
  }
  TreeNode<T>* curr = root;
  TreeNode<T>* parent = root;
  bool isLeft = true;

  while(curr->key != k){
    parent = curr;
    if(k < curr->key){
      isLeft = true;
      curr = curr->left;
    } else{
      isLeft = false;
      curr = curr->right;
    }
  }
  if(curr->left == NULL && curr->right == NULL){
    if(curr == root){
      root = NULL;
    } else if(isLeft){
      parent->left = NULL;
    } else{
      parent->right = NULL;
    }
  } else if(curr->right == NULL){
    if(curr == root){
      root = curr->left;
    } else if(isLeft){
      parent->left = curr->left;
    } else{
      parent->right = curr->right;
    }
  } else if(curr->left == NULL){
    if(curr == root){
      root == curr->right;
    } else if(isLeft){
      parent->right = curr->right;
    } else{
      parent->left = curr->left;
    }
  } else{
    TreeNode<T>* succ = getSucc(curr);
    if(curr == root){
      root = succ;
    } else if(isLeft){
      parent->left = succ;
    } else{
      parent->rigth = succ;
    }
    succ->left = curr->left;
    return true;
  }
}

template <class T>
bool BST<T>::isEmpty(){
  return(root == NULL);
}

template <class T>
T BST<T>::search(T val){
  TreeNode<T> *curr = root;
  while(curr->key != val){
    if(val < curr->key){
      curr = curr->left;
    } else{
      curr = curr->right;
    }
  }
  return curr->key;
}

template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

template <class T>
TreeNode<T>* BST<T>::getSucc(TreeNode<T>* d){
  TreeNode<T>* sp = d;
  TreeNode<T>* succ = d;
  TreeNode<T>* curr = d->right;

  while(curr != NULL){
    sp = succ;
    succ = curr;
    curr = curr->left;
  }

  if(succ != d->right){
    sp->left = succ->right;
    succ->right = d->right;
  }
  return succ;
}

template <class T>
void BST<T>::treeToFile(ofstream& file){
  return treeToFile(root, file);
}

template <class T>
void BST<T>::treeToFile(TreeNode<T>* root, ofstream& file){
  if(root == NULL){
    file << "#" << endl;
    return;
  }
  file << root->key << endl;
  treeToFile(root->left, file);
  treeToFile(root->right, file);
}
