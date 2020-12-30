#include <iostream>
#include "chain_template.cc"

int main()
{
  Chain<int> *chain = new Chain<int>();
  chain->Insert(1);
  chain->Insert(2);
  chain->Insert(3);
  chain->PrintNodes();
  return 0;
}
