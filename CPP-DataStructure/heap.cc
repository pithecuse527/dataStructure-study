#include <iostream>
using namespace std;

class MaxHeap{
public:
  MaxHeap(){
    heap_lst = new int[11]; // not using index 0
    lst_len = 11;
    last_loc = 10;
  }

  void setLst(int* l){ heap_lst = l; }

  void insert_(int e){
    if(++last_loc >= lst_len){
      int *new_heap_lst = new int[lst_len*2];
      copy(heap_lst, heap_lst+lst_len, new_heap_lst);
      lst_len *=2;
      // delete []heap_lst;
      heap_lst = new_heap_lst;
    }

    int i = last_loc;
    heap_lst[i] = e;
    while(i != 1 && heap_lst[i] > heap_lst[i/2]){
      swap(heap_lst[i], heap_lst[i/2]);
      i /= 2;
    }
  }

  int delete_(){
    if(last_loc == 1) return heap_lst[last_loc];
    int to_return = heap_lst[1];
    swap(heap_lst[1], heap_lst[last_loc]);
    last_loc--;
    int p = 1, c = 2;

    while(c <= last_loc){
        if(heap_lst[c] < heap_lst[c+1]) c++;
        if(heap_lst[p] < heap_lst[c]) swap(heap_lst[p], heap_lst[c]);
        p = c;
        c *= 2;
    }
    return to_return;
  }

  void printlst(){
    for(int i=1; i<=last_loc; i++) cout << heap_lst[i] << " ";
    cout << endl;
  }

  bool isEmpty(){
    return last_loc == 0;
  }

private:
  int *heap_lst;
  int lst_len;
  int last_loc;
};

int main()
{
  int my_lst[11] = {-1, 9,7,6,5,4,3,2,2,1,3};
  MaxHeap *my_heap = new MaxHeap();
  my_heap->setLst(my_lst);
  //cout << my_heap->delete_() << endl;
  my_heap->insert_(8);
  my_heap->printlst();
  return 0;
}
