#ifndef TREE_H
#include "../ch3/stack.h"

template <class T> class Tree;

template <class T>
class TreeNode {
  friend class Tree<T>;
public:
  TreeNode(T data, TreeNode<T>* l, TreeNode<T>* r);

private:
  T data;
  TreeNode<T> *leftChild;
  TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:
  Tree(TreeNode<T> *currentNode);
  void Visit(TreeNode<T> *currentNode);
  void Inorder();
  void Inorder(TreeNode<T> *currentNode);
  void Preorder();
  void Preorder(TreeNode<T> *currentNode);
  void Postorder();
  void Postorder(TreeNode<T> *currentNode);
  int NodeCounter(TreeNode<T> *currentNode);
  class InorderIterator;

private:
  TreeNode<T> *root;
};

#endif
