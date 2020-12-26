#include "bag.h"
#include <algorithm>

template <class T>
Bag<T>::Bag(int bagCapacity): capacity(bagCapacity) {
  if(capacity < 1) throw "Capacity must be >0";
  array = new T[capacity];
  top = -1;
}

template <class T>
Bag<T>::~Bag() { delete []array; }

template <class T>
inline int Bag<T>::Size() const { return top+1; }

template <class T>
inline bool Bag<T>::IsEmpty() const { return capacity==0; }

template <class T>
inline T& Bag<T>::Element() const {
  if(IsEmpty()) throw "Bag is empty";
  return array[0];
}

template <class T>
void Bag<T>::Push(const T& x) {
  if(capacity == top+1) {
      ChangeSize1D(array, capacity, 2*capacity);
      capacity *= 2;
    }
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop() {
  if(IsEmpty()) throw "Bag is empty, cannot delete";
  int deletePos = top / 2;
  std::copy(array + deletePos + 1, array + top + 1, array + deletePos);
  array[top--].~T();
}

template <class T>
void Bag<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
  if(newSize < 0) throw "New length must be >= 0";
  T* temp = new T[newSize]; // new array
  int number = oldSize; // how many elements to copy
  if (oldSize > newSize) number = newSize;
  std::copy(a, a+number, temp);
  delete []a;
  a = temp;
}

void TempFunc()   // no need to execute this function as this is only to solve the link error
{
  Bag<int> tmp;
  tmp.Push(1);
  tmp.Element();
}
