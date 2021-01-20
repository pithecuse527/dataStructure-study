#include <iostream>

int gcd(int a, int b)
{
  if(a<b) std::swap(a,b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main()
{
  std::cout << gcd(30, 17) << std::endl;
  return 0;
}
