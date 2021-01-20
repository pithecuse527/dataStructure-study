#include <iostream>

using namespace std;

void move(int n, char from, char to){
  cout << "move " << n << " from " << from << " to " << to << endl;
}

void hanoi(int n, char from, char to, char by)
{
  if(n == 1) move(n, from, to);    // base case
  else{
    hanoi(n-1, from, by, to);
    move(n, from, to);
    hanoi(n-1, by, to, from);
  }
}

int main()
{
  hanoi(3, 'a', 'c', 'b');
  return 0;
}
