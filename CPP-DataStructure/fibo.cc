#include <iostream>
using namespace std;
int Fibo1(int n)    // recursion
{
  if(n <= 2) return 1;
  return Fibo1(n-1) + Fibo1(n-2);
}

int Fibo2(int n, int *fibo_memo)    // dynamic
{
  if(n <= 2)
  {
    fibo_memo[n] = 1;
    return fibo_memo[n];
  }
  if(fibo_memo[n] == 0)
    fibo_memo[n] = Fibo2(n-2, fibo_memo) + Fibo2(n-1, fibo_memo);
  return fibo_memo[n];
}

int Fibo3(int n)  // just iterative (sort of dynamic)
{
  int *tmp_memo = new int[n];
  if(n <= 2) return 1;
  tmp_memo[0] = tmp_memo[1] = 1;
  for(int i=2; i<n; i++)
  {
    tmp_memo[i] = tmp_memo[i-2] + tmp_memo[i-1];
  }
  return tmp_memo[n-1];
}

int main()
{
  int *fibo_memo = new int[7];
  fill(fibo_memo, fibo_memo+7, 0);
  cout << Fibo1(7) << endl;
  cout << Fibo2(7, fibo_memo) << endl;
  // cout << Fibo2(1) << endl;
  cout << Fibo3(2) << endl;
  cout << Fibo3(7) << endl;
  return 0;
}
