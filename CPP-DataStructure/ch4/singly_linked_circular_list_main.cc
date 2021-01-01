#include <iostream>
#include "singly_linked_circular_list.cc"

int main()
{
  CircularList<double> *tmpCircularList = new CircularList<double>();
  tmpCircularList->InsertFront(3.14);
  tmpCircularList->InsertFront(3.15);
  tmpCircularList->InsertFront(3.16);
  tmpCircularList->PrintNodes();
  delete tmpCircularList;
  tmpCircularList->PrintNodes();
  return 0;
}
