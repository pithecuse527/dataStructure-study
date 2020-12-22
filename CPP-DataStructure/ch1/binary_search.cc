#include <iostream>

int RecursiveBinarySearch(int*, int, int, int);
int IterativeBinarySearch(int*, const int, int);

using namespace std;
int main()
{
  int *listp = new int[10];
  int toFind;
  for(int i=0; i<10; i++)
  {
    listp[i] = i;
    cout << listp[i] << " ";
  }
  cout << endl;
  cout << "Type the value to find : ";
  cin >> toFind;
  int recursiveResult = RecursiveBinarySearch(listp, toFind, 0, 9);
  int iterativeResult = IterativeBinarySearch(listp, 10, toFind);
  cout << recursiveResult << " " << iterativeResult << endl;

  delete []listp;
  return 0;
}

int RecursiveBinarySearch(int *listp, int toFind, int left, int right)
{
  int middle = (left + right) / 2;
  if(left > right) return -1;   // base cae

  if(listp[middle] < toFind) return RecursiveBinarySearch(listp, toFind, middle+1, right);
  else if(listp[middle] > toFind) return RecursiveBinarySearch(listp, toFind, left, middle-1);
  else return middle;
}

int IterativeBinarySearch(int *listp, const int size, int toFind)
{
  int left = 0, right = size-1, middle;
  while(left <= right)
  {
    middle = (left+right) / 2;
    if(listp[middle] < toFind) left = middle+1;
    else if(listp[middle] > toFind) right = middle-1;
    else return middle;
  }
  return -1;  // on fail
}
