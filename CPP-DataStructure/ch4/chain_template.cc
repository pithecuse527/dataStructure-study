#ifndef NULL
#define NULL 0
#endif
#include <iostream>

using namespace std;
template <class T> class Chain;

template <class T>
class ChainNode {
friend class Chain<T>;
public:
  ChainNode(T d, ChainNode<T>* l = NULL): data(d), link(l) {}

private:
  T data;
  ChainNode<T>* link;
};

template <class T>
class Chain {
public:
  Chain(ChainNode<T> *f = NULL, ChainNode<T> *t = NULL):
  first(f), tmp_iterator(t)
  { }

  inline void Insert(T data) {
    if(first)
      first = new ChainNode<T>(data, first);
    else
      first = new ChainNode<T>(data, NULL);

  }

  inline void PrintNodes() {
    tmp_iterator = first;
    while(tmp_iterator)
    {
      cout << tmp_iterator->data << " ";
      tmp_iterator = tmp_iterator->link;
    }
    cout << endl;
  }

private:
  ChainNode<T> *first;
  ChainNode<T> *tmp_iterator;
};
