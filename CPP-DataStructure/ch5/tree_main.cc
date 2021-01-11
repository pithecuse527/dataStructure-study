#include <iostream>
#include "tree.h"

int main()
{
  TreeNode<int> n4(4, NULL, NULL);
  TreeNode<int> n2(2, &n4, NULL);
  TreeNode<int> n3(3, NULL, NULL);
  TreeNode<int> n1(1, &n2, &n3);
  Tree<int> *testTree= new Tree<int>(&n1);
  testTree -> Inorder();
  std::cout << std::endl;
  testTree -> Preorder();
  std::cout << std::endl;
  testTree -> Postorder();
  std::cout << std::endl;
  std::cout << testTree->NodeCounter(&n1) << std::endl;

  return 0;
}
