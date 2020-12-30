#include <iostream>

using namespace std;

int main()
{
  int x[3] = {0, 1, 2};
  for(int* y=x; y!=x+3; y++)    // not sure what address is for x+3
    cout << y << " " << *y << " ";
  cout << endl;

  return 0;
}
