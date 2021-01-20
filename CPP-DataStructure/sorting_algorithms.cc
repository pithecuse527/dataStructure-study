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
  void insertionsort(T* lst, const int n)
  {
    int key, i, j;

    for(i=1; i<n; i++){
      key = lst[i];
      for(j=i-1; j>=0 && lst[j] > key; j--){
        lst[j+1] = lst[j];
      }
      lst[j+1] = key;
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


  // Merge function which will be used after division
  void Merge(T* lst, int left, int mid, int right){
    int i,j,k;
    i = left;  j = mid+1;  k = left;
    int *slst = new int[right-left+1];  // tep. list to save sorted elements

    while(i<=mid && j<=right){  // pick some elements in a sorted way
      if(lst[i] <= lst[j]) slst[k++] = lst[i++];
      else slst[k++] = lst[j++];
    }

    // leftovers
    for(int l=i; l<=mid; l++) slst[k++] = lst[l];
    for(int l=j; l<=right; l++) slst[k++] = lst[l];

    // save the sorted list's elements to the given unsorted list
    for(int l=left; l<=right; l++) lst[l] = slst[l];
  }

  // Driver
  // Divide until the length of lst is 1
  void MergeSort(T* lst, int left, int right){
    int mid;
    if(left < right){
      mid = (left+right)/2;
      MergeSort(lst, left, mid);    // divide left part
      MergeSort(lst, mid+1, right); // divide right part
      Merge(lst, left, mid, right); // and merge them
    }
  }

  // insertion sort for shell sort
  // use gap to sort the part of unsorted list
  void ShellInsertionSort(T* lst, int left, int right, int gap){
    int i, j, key;

    for(i=left+gap; i<=right; i += gap){
      key = lst[i];
      for(j=i-gap; j>=left && key<lst[j]; j -= gap){
        lst[j+gap] = lst[j];
      }
      lst[j+gap] = key;
    }
  }

  // Driver
  // invoke the insortion sort with some gap
  void ShellSort(T* lst, int n){
    for(int gap=n/2; gap>0; gap /=2){
      if((gap%2) == 0) gap++;
      for(int i=0; i<gap; i++){
        ShellInsertionSort(lst, i, n-1, gap);
      }
    }
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
  PrintList(unsorted_lst, 10);
  tmp_machine->ShellSort(unsorted_lst, 10);
  PrintList(unsorted_lst, 10);
  cout << endl;
  //cout << tmp_machine->BinarySearch(unsorted_lst, 37, 0, 9) << endl;

  delete [] unsorted_lst;
  return 0;
}

template <class T>
void PrintList(T* lst, int size){
  for(int i=0; i<size; i++) cout << lst[i] << " ";
  cout << endl;
}
