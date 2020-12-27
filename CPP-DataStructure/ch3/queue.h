#ifndef QUEUE_H
#define QUEUE_H
template <class T>
class Queue
{
public:
  Queue(int queueCapacity=10);
  bool IsEmpty() const;
  T& Front() const;
  T& Rear() const;
  void Push(const T& item);
  void Pop();
  void ChangeSize1D(T*& a, const int oldSize, const int newSize);

private:
  T* queue;
  int front;
  int rear;
  int capacity;
};
#endif
