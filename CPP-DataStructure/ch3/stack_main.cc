#include <iostream>
#include "stack.h"
#include "stack.cc"

using namespace std;
int main()
{
  Stack<double> *myStack = new Stack<double>(10);
  cout << myStack->IsEmpty() << endl;
  myStack->Push(3.14);
  myStack->Push(3.17);
  cout << myStack->Top() << endl;
  myStack->Pop();
  cout << myStack->Top() << endl;
  myStack->Pop();
  cout << myStack->IsEmpty() << endl;
  return 0;
}
