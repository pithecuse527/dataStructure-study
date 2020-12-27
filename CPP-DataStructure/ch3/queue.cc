#include "queue.h"
#include <algorithm>

template <class T>
Queue<T>::Queue(int queueuCapacity): capacity(queueuCapacity)
{
  if(capacity < 1) throw "Queue capacity must be >0";
  queue = new T[capacity];
  front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const { return front == rear; }

template <class T>
inline T& Queue<T>::Front() const
{
  if(IsEmpty()) throw "Queue is empty";
  return queue[(front+1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const
{
  if(IsEmpty()) throw "Queue is empty";
  return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& item)
{
  if((rear+1)%capacity == front)
  {
    ChangeSize1D(queue, capacity, 2*capacity);
    capacity *= 2;
  }
  rear = (rear+1) % capacity;
  queue[rear] = item;
}

template <class T>
void Queue<T>::Pop()
{
  if(IsEmpty()) throw "Queue is empty";
  front = (front+1) % capacity;
  queue[front].~T();
}

template <class T>
void Queue<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
  if(newSize < 0) throw "New length must be >= 0";
  T* temp = new T[newSize]; // new array
  int number = oldSize; // how many elements to copy
  if (oldSize > newSize) number = newSize;
  std::copy(a, a+number, temp);
  delete []a;
  a = temp;
}
