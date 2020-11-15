//
//  main.c
//  experimentation_180601
//
//  Created by Ji Hong Guen on 5/31/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "main2.c"
#include "main3.c"
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }
                            // mem = malloc(size)     --> This code do not need type conversion...
                            //                            Since the variable mem would be have it's pointer type.

typedef char element;

typedef struct treeNode{
    element data;
    struct treeNode *lchild, *rchild;
}treeNode;

typedef treeNode *t_ptr;

void inOrder(t_ptr ptr);
void preOrder(t_ptr ptr);
void postOrder(t_ptr ptr);
t_ptr copy(t_ptr ori);
int equal(t_ptr first, t_ptr second);

int main(int argc, const char * argv[]) {

    t_ptr Tnode1;
    t_ptr Tnode2;
    t_ptr Tnode3;
    t_ptr Tnode4;
    t_ptr Tnode5;
    t_ptr Tnode6;
    t_ptr Tnode7;

    MALLOC(Tnode1, sizeof(*Tnode1));
    MALLOC(Tnode2, sizeof(*Tnode2));
    MALLOC(Tnode3, sizeof(*Tnode3));
    MALLOC(Tnode4, sizeof(*Tnode4));
    MALLOC(Tnode5, sizeof(*Tnode5));
    MALLOC(Tnode6, sizeof(*Tnode6));
    MALLOC(Tnode7, sizeof(*Tnode7));

    Tnode1 -> data = 'A';
    Tnode1 -> lchild = Tnode2;
    Tnode1 -> rchild = Tnode3;

    Tnode2 -> data = 'B';
    Tnode2 -> lchild = Tnode4;
    Tnode2 -> rchild = Tnode4;

    Tnode3 -> data = 'E';
    Tnode3 -> lchild = Tnode6;
    Tnode3 -> rchild = Tnode7;

    Tnode4 -> data = 'C';
    Tnode4 -> lchild = NULL;
    Tnode4 -> rchild = NULL;

    Tnode5 -> data = 'D';
    Tnode5 -> lchild = NULL;
    Tnode5 -> rchild = NULL;

    Tnode6 -> data = 'F';
    Tnode6 -> lchild = NULL;
    Tnode6 -> rchild = NULL;

    Tnode7 -> data = 'G';
    Tnode7 -> lchild = NULL;
    Tnode7 -> rchild = NULL;



}

void inOrder(t_ptr ptr)
{
    if(ptr)
    {
        inOrder(ptr -> lchild);
        printf("%c ",ptr -> data);
        inOrder(ptr -> rchild);
    }
}

void preOrder(t_ptr ptr)
{
    if(ptr)
    {
        printf("%c ",ptr -> data);
        inOrder(ptr -> lchild);
        inOrder(ptr -> rchild);
    }
}

void postOrder(t_ptr ptr)
{
    if(ptr)
    {
        inOrder(ptr -> lchild);
        inOrder(ptr -> rchild);
        printf("%c ",ptr -> data);
    }
}

t_ptr copy(t_ptr ori)
{
    t_ptr temp;
    if (ori){
        MALLOC(temp, sizeof(*temp));
        temp -> lchild = copy(ori -> lchild);
        temp -> rchild = copy(ori -> rchild);
        temp -> data = ori -> data;
        return temp;
    }
    return NULL;
}


int equal(t_ptr first, t_ptr second)
{
    return ((!first && !second) || (first && second &&
                                    (first -> data == second -> data) &&
                                    equal(first -> lchild, second -> lchild) &&
                                    equal(first -> rchild, second -> rchild)));
}
