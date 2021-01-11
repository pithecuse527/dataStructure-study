#include "tree.h"
#include "../ch3/stack.cc"
#include <iostream>

using namespace std;

template <class T>
TreeNode<T>::TreeNode(T d, TreeNode<T>* l, TreeNode<T>* r)
{
  data = d;
  leftChild = l;
  rightChild = r;
}

template <class T>
Tree<T>::Tree(TreeNode<T> *currentNode)
{
  root = currentNode;
}

template <class T>
void Tree<T>::Visit(TreeNode<T> *currentNode)
{
    cout << " " << currentNode->data;
}

template <class T>
void Tree<T>::Inorder()
{
  Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode)
{
  if(currentNode) {
    Inorder(currentNode -> leftChild);
    Visit(currentNode);
    Inorder(currentNode -> rightChild);
  }
}

template <class T>
void Tree<T>::Preorder()
{
  Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T> *currentNode)
{
  if(currentNode) {
    Visit(currentNode);
    Preorder(currentNode -> leftChild);
    Preorder(currentNode -> rightChild);
  }
}

template <class T>
void Tree<T>::Postorder()
{
  Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode)
{
  if(currentNode) {
    Postorder(currentNode -> leftChild);
    Postorder(currentNode -> rightChild);
    Visit(currentNode);
  }
}

template <class T>
class Tree<T>::InorderIterator {
friend class Tree<T>;
public:
  InorderIterator(const Tree<T>& e){currentNode = e.root;}
  T* Next()
  {
    while(currentNode)
    {
      s.Push(currentNode);
      currentNode = currentNode -> leftChild;
    }
    if(s.IsEmpty()) return 0;
    currentNode = s.Top();
    s.Pop();
    T& temp = currentNode -> data;
    currentNode = currentNode -> rightChild;
    return &temp;
  }
private:
  Stack<TreeNode<T>*> s;
  TreeNode<T> *currentNode;
};

template <class T>
int Tree<T>::NodeCounter(TreeNode<T> *currentNode)
{
  int sum = 0;
  if(currentNode) {
    sum += NodeCounter(currentNode->leftChild);
    sum += 1;
    sum += NodeCounter(currentNode->rightChild);
  }
  return sum;
}

// just a temporary function to solve the linking problem with the template
// no need to call this
void TempFunc()
{
  TreeNode<int> temp1(1, NULL, NULL);
  Tree<int> temp2(&temp1);
  temp2.Inorder();
  temp2.Preorder();
  temp2.Postorder();
  temp2.NodeCounter(&temp1);
}
