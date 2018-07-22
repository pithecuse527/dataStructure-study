//
//  main3.c
//  experimentation_180601
//
//  Created by Ji Hong Guen on 6/1/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200 /* 최대 히프 크기 + 1*/
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }
                            // mem = malloc(size)     --> This code do not need type conversion...
                            //                            Since the variable mem would be have it's pointer type.

typedef struct element{
    int key;
} element;

void push(element item, int *n);
element pop(int *n);

element heap[MAX_ELEMENTS];
int n = 0;

void main3()
{

}

void push(element item, int *n)
{
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full. \n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);

    while ( (i != 1) && (item.key > heap[i/2].key) )
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

element pop(int *n)
{
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n))
    {
        fprintf(stderr, "The heap is empty. \n");
        exit(EXIT_FAILURE);
    }

    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n)
    {
        if ((child < *n) && (heap[child].key < heap[child+1].key)) child++;
        if (temp.key >= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
