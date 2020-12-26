#ifndef BAG_H
#define BAG_H
template <class T>
class Bag
{
public:
  Bag (int bagCapacity = 10); // constructor
  ~Bag(); // destroyer
  int Size() const;
  bool IsEmpty() const;
  T& Element() const;
  void Push(const T&);
  void Pop();
  void ChangeSize1D(T*& a, const int oldSize, const int newSize);

private:
  T *array;
  int capacity;
  int top;
};
#endif
