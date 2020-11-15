//
//  main2.c
//  experimentation_180601
//
//  Created by Ji Hong Guen on 5/31/18.
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

typedef char element;
typedef struct threadTree *thr_ptr;

typedef struct threadTree {
    short int lthread;
    thr_ptr lchild;
    element data;
    thr_ptr rchild;
    short int rthread;
} threadTree;


thr_ptr insucc(thr_ptr tree);
void tinorder(thr_ptr tree);
void insertRight(thr_ptr s, thr_ptr r);


void main2()
{

}

thr_ptr insucc(thr_ptr tree)
{
    thr_ptr temp;
    temp = tree -> rchild;
    if(!tree -> rthread)
        while (!temp -> lthread)
            temp = temp -> lchild;
    return temp;
}

void tinorder(thr_ptr tree)
{
    thr_ptr temp = tree;
    for(;;)
    {
        temp = insucc(temp);
        if (temp == tree) break;
        printf("%3c", temp -> data);
    }
}

void insertRight(thr_ptr s, thr_ptr r)
{
    thr_ptr temp;
    r -> rchild = s -> rchild;
    r -> rthread = s -> rthread;
    r -> lchild = s;
    r -> lthread = 1;
    s -> rchild = r;
    s -> rthread = 0;

    if (!r -> rthread)
    {
        temp = insucc(r);
        temp -> lchild = r;
    }
}

