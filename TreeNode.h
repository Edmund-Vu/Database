#include <cstddef>

using namespace std;

template <class T>
class TreeNode{
  public:
    T key;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(T k);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
  key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete left;
  delete right;
}
