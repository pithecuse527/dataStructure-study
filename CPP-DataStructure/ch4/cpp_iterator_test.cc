#include <iostream>

using namespace std;

int main()
{
  int x[3] = {0, 1, 2};
  for(int* y=x; y!=x+3; y++)    // not sure what address is for x+3 (address x+3 supposed to be not exist)
    cout << y << " " << *y << " ";
  cout << endl;

  return 0;
}
