//
//  main.c
//  experimentation_180523
//
//  Created by Ji Hong Guen on 5/23/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                                fprintf(stderr, "Insufficient memory!");\
                                exit(EXIT_FAILURE);\
                                }
                            // mem = malloc(size)     --> This code do not need type conversion...
                            //                            Since the variable mem would be have it's pointer type.
typedef int element;
typedef struct node{
    element n;
    struct node *link;
} poly;

typedef poly *poly_ptr;

poly_ptr getAvailNode(poly_ptr *avail);
void returnNode(poly_ptr ptr, poly_ptr *avail);
void cerase(poly_ptr *ptr, poly_ptr *avail);            // This is much like setAvailNode()

int main(int argc, const char * argv[]) {

    poly_ptr node1, node2, node3, node4, node5, header, avail;

    MALLOC(node1, sizeof(*node1));
    MALLOC(node2, sizeof(*node2));
    MALLOC(node3, sizeof(*node3));
    MALLOC(node4, sizeof(*node4));
    MALLOC(node5, sizeof(*node5));

    node1 -> n = 1;
    node2 -> n = 2;
    node3 -> n = 3;
    node4 -> n = 4;
    node5 -> n = 5;

    node1 -> link = node2;
    node2 -> link = node3;
    node3 -> link = node4;
    node4 -> link = node5;
    node5 -> link = node1;

    header = node1;                         // node1 == header
    avail = NULL;

    printf("This is original linked list...\n");

    for(poly_ptr a = node1; a; a = a -> link)
    {
        printf("[%d, %4d] ", a -> n, a -> link);
        if(a -> link != node1) printf("-> ");
        if(a -> link == node1) break;
    }
    printf("\n\n\n");

    printf("This is avail linked list...\n");
    cerase(&header, &avail);
    int i=0;
    for(poly_ptr a = avail; a; a = a -> link)
    {
        printf("[%d, %4d] ", a -> n, a -> link);
        printf("-> ");
        if(++i == 5) break;
    }
    printf("\n");


}

poly_ptr getAvailNode(poly_ptr *avail)
{
    poly_ptr node;
    if(*avail)
    {
        node = *avail;
        *avail = (*avail) -> link;
    }
    else MALLOC(node, sizeof(*node));
    return node;
}

void returnNode(poly_ptr ptr, poly_ptr *avail)
{
    ptr -> link = *avail;
    *avail = ptr;
}

void cerase(poly_ptr *ptr, poly_ptr *avail)
{
    poly_ptr temp;

    if(*ptr)
    {
        temp = (*ptr) -> link;
        (*ptr) -> link = *avail;
        *avail = temp;
        *ptr = NULL;
    }
}


