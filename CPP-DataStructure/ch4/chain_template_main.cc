#include <iostream>
#include "chain_template.cc"

int main()
{
  Chain<int> *testChain = new Chain<int>();
  testChain->InsertBack(0); // 0
  testChain->InsertBack(1); // 0 -> 1
  // testChain->PrintNodes();
  testChain->InsertBack(5); // 0 -> 1 -> 5
  // testChain->PrintNodes();

  Chain<int> *testChain2 = new Chain<int>();
  testChain2->InsertBack(11); // 11
  testChain2->InsertBack(12); // 12
  testChain2->PrintNodes();
  testChain2->Concatenate(*testChain);
  testChain2->PrintNodes();

  return 0;
}
