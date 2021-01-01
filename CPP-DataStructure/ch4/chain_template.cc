#ifndef NULL
#define NULL 0
#endif
#include <iostream>

using namespace std;
template <class T> class Chain;
template <class T> class ChainNode;

template <class T>
class Chain {
public:
  Chain(): first(NULL), last(NULL) {}

  // inherited class
  class ChainIterator {
  friend class Chain<T>;
  public:
    ChainIterator(ChainNode<T>* startNode = NULL): current(startNode)
    { }

    // operators for pointer
    T& operator*() const {return current -> data;}
    T* operator->() const {return &current->data;}

    // operators for increment
    ChainIterator& operator++() // prefix increment
    {current = current->link; return *this;}
    ChainIterator operator++(int) // postfix increment
    {ChainIterator old = *this; current = current->link; return old;}

    // operators for equivalence
    bool operator!=(const ChainIterator rightOne) const
    {return current != rightOne.current;}
    bool operator==(const ChainIterator rightOne) const
    {return current == rightOne.current;}

  private:
    ChainNode<T>* current;
  }; // end inherit class

  void InsertBack(const T& e)
  {
    if(first)
    {
      last->link = new ChainNode<T>(e);
      last = last -> link;
    }
    else first = last = new ChainNode<T>(e);
  }

  void Concatenate(Chain<T>& b)
  {
    if(first) {last -> link = b.first; last = b.last;}
    else {first = b.first; last = b.last;}
    b.last = b.first = NULL;  // b is now the part of *this
  }

  void PrintNodes()
  {
    ChainIterator iter(first);
    while(iter.current != NULL)
    {
      cout << (iter.current)->data << " ";
      iter++;
    }
    cout << endl;
  }

  void Reverse()
  {
    ChainIterator iter(first);
    ChainIterator iterPrev;

    while(iter++ != NULL)
    {
      iterPrev = iter++;
      iter.current -> link = iterPrev.current;
    }
    first = iterPrev.current;
  }

private:
  ChainNode<T>* first;
  ChainNode<T>* last;
};


template <class T>
class ChainNode {
friend class Chain<T>;
public:
  ChainNode(T d, ChainNode<T>* l = NULL):
  data(d), link(l) { }

private:
  T data;
  ChainNode<T>* link;
};
