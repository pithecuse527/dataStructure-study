#include <iostream>
#define SWAP(a, b) {int tmp; tmp=a; a=b; b=tmp;}

void Permutation(int*, int, int);
using namespace std;

int main()
{
  int *lstp = new int[5];
  for(int i=0; i<5; i++) lstp[i] = i;
  Permutation(lstp, 0, 5);
  return 0;
}

// lstp := set for Permutation
// runner := runner to be a pivot of the permutation
// n := size of the set
void Permutation(int *lstp, int runner, int n)
{
  if (runner == n - 1)  // if runner reaches to the end, print the list
  {
    for(int i=0; i<n; i++) cout << lstp[i] << " ";
    cout << endl;
  }
  else
  {
    for(int i=runner; i<n; i++)
    {
      SWAP(lstp[runner], lstp[i]);
      Permutation(lstp, runner+1, n);
      SWAP(lstp[runner], lstp[i]);
    }
  }
}
