#include <iostream>
#include "bag.h"

using namespace std;
int main()
{
  Bag<int> *my_bag = new Bag<int>(5);
  Bag<int> my_bag2(2);

  my_bag->Push(5);
  my_bag2.Push(1);

  cout << my_bag->Element() << endl;
  cout << my_bag2.Element() << endl;

  return 0;

}
