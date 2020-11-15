//
//  main.c
//  playGround
//
//  Created by Ji Hong Guen on 4/14/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 50
#define HEAP_FULL(n) ( (n) == MAX_HEAP_SIZE - 1 )
#define HEAP_EMPTY(n) ( !n )

typedef struct element{
    int key;
}element;
element heap[MAX_HEAP_SIZE];

void insertMaxHeap(element item, int *n);
element pop(int *n);

int main(void)
{

}

void insertMaxHeap(element item, int *n)
{
    int i;
    if(HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while( (i != 1) && (item.key > heap[i/2].key) ){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;

}

element pop(int *n)
{
    int parent, child;
    element item, temp;
    if(HEAP_EMPTY(*n)){
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while(child <= *n){
        if( (child < *n) && (heap[child].key < heap[child+1].key) )
            child++;
        if( temp.key >= heap[child].key ) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
