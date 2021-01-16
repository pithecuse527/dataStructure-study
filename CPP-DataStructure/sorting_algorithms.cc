//
//  sorting_algorithms.cc
//
//  Created by Ji Hong Guen on 2021. 15. Jan.
//  some basic sortihg algorithms using the SortMachine class
//

#include <iostream>
#include <cstdlib>
#ifndef NULL
#define NULL 0
#endif
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

using namespace std;

template <class T>
void PrintList(T* lst, int size);

template <class T>
class SortMachine
{
// Sorthing machine which does not have any member variables
// Will only takes the list to be sorted when sort action needed
public:
  void BubbleSort(T* lst, int size){
    int tmp;
    for(int i=size-1; i > 0; i--){  // set the boundary
      for(int j=0; j<i; j++){ // the max value will be bubbled up until it reaches the boundary
        if(lst[j] > lst[j+1]) SWAP(lst[j], lst[j+1], tmp);
      }
      PrintList(lst, 10); // check the list every time
    }
  }

  void SelectionSort(T* lst, int size){
    int tmp, min;
    for(int i=0; i<size-1; i++){
      min = i;  // select the most left one as a temp min,
      for(int j=i+1; j<size; j++){
        if(lst[min] > lst[j]) min = j;
      }
      SWAP(lst[i], lst[min], tmp);  // swap at once
      PrintList(lst, 10); // check the list every time
    }
  }

  // you know how this works if, and only if, you know how selection sort works (vice versa)
  void InsertionSort(T* lst, int size){
    int tmp;
    int swap_loc;
    for(int i=0; i<size-1; i++){  // subset boundary
      for(int j=i+1; j>0 && lst[j-1] > lst[j]; j--) // find the location for lst[i+1] by swap
        SWAP(lst[j-1], lst[j], tmp);
      PrintList(lst, 10); // check the list every time
    }
  }

  // sort lst[left:right] as an ascending order
  // lst[left] is a temp pivot
  void QuickSort(T *lst, const int left, const int right)
  {
    if(left < right){ // base case
      int i = left, j = right+1;
      int pivot = lst[left];  // pivot will be moved to appropriate location
      do{
        do i++; while(lst[i]<pivot);  // i moves to right
        do j--; while(lst[j]>pivot);  // j moves to left
        if(i<j) std::swap(lst[i], lst[j]);  // left subset has smaller values and right subset has bigger values
      } while(i<j);
      std::swap(lst[left], lst[j]); // pivot(lst[left]) should be moved to the middle of two sublist

      this->QuickSort(lst, left, j-1);  // recursion for the left subset
      this->QuickSort(lst, j+1, right); // recursion for the right subset
    }
  }

  // binary search with O(logn)
  // give a location of e
  // lst should be sorted
  int BinarySearch(T *lst, const T e, int left, int right)
  {
    if(left > right) return -1; // base case1
    int middle = (left+right) / 2;
    if(lst[middle] < e) return BinarySearch(lst, e, middle+1, right); // use right sublist
    else if(lst[middle] > e) return BinarySearch(lst, e, left, middle-1); // use left sublist
    else return middle; // base case2
  }
};

int main()
{
  SortMachine<int> *tmp_machine = new SortMachine<int>();
  int *unsorted_lst = new int[10];
  for(int i=0; i<10; i++) unsorted_lst[i] = (rand() % 35) + 1;
  // PrintList(unsorted_lst, 10);
  // tmp_machine->BubbleSort(unsorted_lst, 10);
  // cout << endl;
  //
  // for(int i=0; i<10; i++) unsorted_lst[i] = (rand() % 35) + 1;
  // tmp_machine->SelectionSort(unsorted_lst, 10);
  // cout << endl;
  //
  // for(int i=0; i<10; i++) unsorted_lst[i] = (rand() % 35) + 1;
  // tmp_machine->InsertionSort(unsorted_lst, 10);
  // cout << endl;

  for(int i=0; i<9; i++) unsorted_lst[i] = (rand() % 35) + 1;
  unsorted_lst[9] = 37;
  tmp_machine->QuickSort(unsorted_lst, 0, 9);
  PrintList(unsorted_lst, 9);
  cout << endl;
  cout << tmp_machine->BinarySearch(unsorted_lst, 37, 0, 9) << endl;

  delete [] unsorted_lst;
  return 0;
}

template <class T>
void PrintList(T* lst, int size){
  for(int i=0; i<10; i++) cout << lst[i] << " ";
  cout << endl;
}
