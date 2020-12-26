#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
  Stack(int stackCapacity = 10);
  bool IsEmpty() const;
  T& Top() const;
  void Push(const T& item);
  void Pop();
  void ChangeSize1D(T*& a, const int oldSize, const int newSize);

private:
  T* stack; // array for the stack elements
  int top;
  int capacity;
};

#endif
