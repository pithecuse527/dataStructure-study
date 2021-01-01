#ifndef NULL
#define NULL 0
#endif
#include "chain_template.cc"
#include <iostream>

using namespace std;
template <class T> class CircularList;
template <class T> class ListNode;
template <class T> class ChainNode;

template <class T>
class CircularList{
public:
  CircularList(): last(NULL), av(NULL) { }
  ~CircularList() // remove circular list
  {
    if(last) {
      ChainNode<T>* first = last -> link;
      last -> link = av;  // this chain is attached to av
      av = first;   // av moved to first of this
      last = NULL;  // pretend this is removed
    }
  }

  // inherited class iterator
  class ChainIterator {
  friend class CircularList<T>;
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

  // add the element e to the first point of *this
  void InsertFront(const T& e)
  {
    ChainNode<T> *newNode = new ChainNode<T>(e);
    if(last) {
      newNode->link = last->link;
      last->link = newNode;
    }
    else {
      last = newNode;
      newNode -> link = newNode;
    }
  }

  // print the node data with ChainIterator
  void PrintNodes()
  {
    if(last) // if the chain is not empty,
    {
      if(last->link == last){ // if the chain includes only one node,
        cout << last->data << endl;
        return;
      }

      // else,
      ChainIterator iter(last->link);
      while(iter.current != last) // while iterator still on the loop
      {
        cout << (iter.current)->data << " ";
        iter++;
      }
      cout << (iter.current)->data << endl;
    }
    else cout << "The chain is empty" << endl;
  }

private:
  ChainNode<T>* last;
  ChainNode<T>* av;
};
