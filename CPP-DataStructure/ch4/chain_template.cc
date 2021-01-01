#ifndef NULL
#define NULL 0
#endif
#include <iostream>

using namespace std;
template <class T> class Chain;
template <class T> class ChainNode;
template <class T> class CircularList;

template <class T>
class Chain {
public:
  Chain(): first(NULL), last(NULL) {}

  // inherited class iterator
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

  // insert a new node right afte the last
  void InsertBack(const T& e)
  {
    if(first) // if first exist, just add to the last
    {
      last->link = new ChainNode<T>(e);
      last = last -> link;
    }
    else first = last = new ChainNode<T>(e); // if not, first and last will be a new node
  }

  // concatenate two chain
  void Concatenate(Chain<T>& b)
  {
    // the given chain parameter will be attach to *this
    if(first) {last -> link = b.first; last = b.last;}
    else {first = b.first; last = b.last;}
    b.last = b.first = NULL;  // b is now the part of *this
  }

  // print the node data with ChainIterator
  void PrintNodes()
  {
    ChainIterator iter(first);
    while(iter.current != NULL) // while iterator still on the loop
    {
      cout << (iter.current)->data << " ";
      iter++;
    }
    cout << endl;
  }

  // reverse order of the chain with ChainIterator
  void Reverse()
  {
    ChainIterator iter(first);
    ChainIterator iterPrev;

    while(iter.current != NULL) // while iterator still on the loop
    {
      iterPrev = iter++;
      iter.current -> link = iterPrev.current;
      ++iter;
    }
    first = iterPrev.current; // last will be the first of this chain
  }

private:
  ChainNode<T>* first;
  ChainNode<T>* last;
};

// the class ChainNode which will be a node of the Chain
template <class T>
class ChainNode {
friend class Chain<T>;
friend class CircularList<T>;
public:
  ChainNode(T d, ChainNode<T>* l = NULL):
  data(d), link(l) { }

private:
  T data;
  ChainNode<T>* link;
};
