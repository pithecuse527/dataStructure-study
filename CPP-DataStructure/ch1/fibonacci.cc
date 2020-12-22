#include <iostream>

using namespace std;
int main()
{
  int n = 10;
  int fn; int fnm1 = 0; int fnm2 = 1;
  cout << fnm1 << " " << fnm2 << " ";
  for(int i=2; i<=n; i++)
  {
      fn = fnm1 + fnm2;
      fnm1 = fnm2;
      fnm2 = fn;
      cout << fn << " ";
  }
  cout << endl;
}
