//
//  main3.c
//  180504_experimentation
//
//  Created by Ji Hong Guen on 5/11/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *Llink;
    struct DlistNode *Rlink;
} DlistNode;

void add(DlistNode *Hnode, DlistNode *newNode);
void add2(DlistNode *Hnode, DlistNode *newNode);        // More delicate version...
void display_r(DlistNode *Hnode);
void display_l(DlistNode *Hnode);

int main()
{

    DlistNode *Hnode;
    Hnode = (DlistNode *)malloc(sizeof(DlistNode));
    //Hnode -> data = 0;
    Hnode -> Llink = NULL;
    Hnode -> Rlink = NULL;


    DlistNode *p1;
    p1 = (DlistNode *)malloc(sizeof(DlistNode));
    p1 -> data = 1;
    p1 -> Llink = NULL;
    p1 -> Rlink = NULL;
    Hnode -> Rlink = p1;

    DlistNode *p2;
    p2 = (DlistNode *)malloc(sizeof(DlistNode));
    p2 -> data = 5;
    p2 -> Llink = NULL;
    p2 -> Rlink = NULL;
    p1 -> Rlink = p2;
    p2 -> Llink = p1;

    DlistNode *p3;
    p3 = (DlistNode *)malloc(sizeof(DlistNode));
    p3 -> data = 7;
    p3 -> Llink = NULL;
    p3 -> Rlink = NULL;
    p2 -> Rlink = p3;
    p3 -> Llink = p2;

    p1 -> Llink = Hnode;
    p3 -> Rlink = Hnode;
    Hnode -> Llink = p3;


    DlistNode *newNode;
    newNode = (DlistNode *)malloc(sizeof(DlistNode));
    newNode -> data = 4;
    newNode -> Llink = NULL;
    newNode -> Rlink = NULL;

    add2(Hnode, newNode);

    display_l(Hnode);
    printf("\n");
    display_r(Hnode);

    return 0;
}

void add(DlistNode *Hnode, DlistNode *newNode)
{
    DlistNode *p1, *p2;

    p1 = Hnode -> Rlink;
    p2 = newNode;

    while (p1 != Hnode)
    {
        if( (p1 -> data <= p2 -> data) && (p2 -> data <= (p1 -> Rlink) -> data) )
        {
            newNode -> Llink = p1;
            newNode -> Rlink = p1 -> Rlink;
            (p1 -> Rlink) -> Llink = newNode;
            p1 -> Rlink = newNode;
            break;
        }

        p1 = p1 -> Rlink;

    }

}

void add2(DlistNode *Hnode, DlistNode *newNode)         // More delicate version...
{
    DlistNode *p1, *p2, *Tp;

    p1 = Hnode -> Rlink;
    p2 = p1 -> Rlink;
    Tp = newNode;

    while (p1 != Hnode)
    {
        if( (p1 -> data <= Tp -> data) && (Tp -> data <= p2 -> data) )
        {
            newNode -> Llink = p1;
            newNode -> Rlink = p2;
            p2 -> Llink = newNode;
            p1 -> Rlink = newNode;
            break;
        }

        p1 = p1 -> Rlink;
        p2 = p2 -> Rlink;

    }

}

void display_r(DlistNode *Hnode)
{
    DlistNode *p = Hnode -> Rlink;

    while (p != Hnode)
    {
        printf("%d  ", p -> data);
        p = p -> Rlink;
    }
    printf("\n");
}

void display_l(DlistNode *Hnode)
{
    DlistNode *p = Hnode -> Llink;

    while (p != Hnode)
    {
        printf("%d  ", p -> data);
        p = p -> Llink;
    }

    printf("\n");
}
