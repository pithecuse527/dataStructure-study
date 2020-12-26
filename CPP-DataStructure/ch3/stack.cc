#include "stack.h"
#include <algorithm>

template <class T>
Stack<T>::Stack(int stackCapacity): capacity(stackCapacity)
{
  if(capacity < 1) throw "Stack capacity must be >0";
  stack = new T[capacity];
  top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const {return top == -1;}

template <class T>
inline T& Stack<T>::Top() const
{
  if(IsEmpty()) throw "Stack is empty";
  return stack[top];
}

template <class T>
void Stack<T>::Pop()
{
  if(IsEmpty()) throw "Stack is empty";
  stack[top--].~T();
}

template <class T>
void Stack<T>::Push(const T& item)
{
    if(top==capacity-1)
    {
      ChangeSize1D(stack, capacity, 2*capacity);
      capacity *= 2;
    }
    stack[++top] = item;
}

template <class T>
void Stack<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
  if(newSize < 0) throw "New length must be >= 0";
  T* temp = new T[newSize]; // new array
  int number = oldSize; // how many elements to copy
  if (oldSize > newSize) number = newSize;
  std::copy(a, a+number, temp);
  delete []a;
  a = temp;
}
