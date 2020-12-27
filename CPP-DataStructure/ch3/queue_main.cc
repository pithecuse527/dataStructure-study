#include <iostream>
#include "queue.h"
#include "queue.cc"

int main()
{
  Queue<int> *myQueue = new Queue<int>;
  myQueue->Push(1);
  myQueue->Push(2);
  myQueue->Pop();
}
