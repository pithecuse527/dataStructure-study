//
//  stack_.c
//  UOU_term_project
//
//  Created by Ji Hong Guen on 6/12/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.c"
#define MAX_STACKS 20
#define MALLOC(p, t, s)  if( !(p = (t*)malloc(s))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }

//stack_ptr initStack(void);                        // Stack initiation.
int isFullStack(stack_ptr sptr);                    // Check whether stack is full or not.
int isEmptyStack(stack_ptr sptr, int reason);       // Check whether stack is empty or not.

void push(precedence val, stack_ptr *sptr_top);     // Push the stack element which value is val to the sptr.
                                                    // sptr is considered as a top in this function.

stack_element pop(stack_ptr *sptr_top);             // Pop the stack element from the sptr.

int isFullStack(stack_ptr sptr)
{
    int count = 0;
    for(; sptr; sptr = sptr -> link) count++;   // Counting.
    if (count == MAX_STACKS){
        fprintf(stderr, "Stack is full!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int isEmptyStack(stack_ptr sptr, int reason)
{
    if(!sptr){
        switch(reason){
            case 1:
                fprintf(stderr, "There is no lparen in stack! So it reaches empty while searching.\n");
                exit(EXIT_FAILURE);
            default:
                fprintf(stderr, "The stack is empty!\n");
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}

void push(precedence val, stack_ptr *sptr_top)
{
    stack_ptr temp = NULL;

    if(!isFullStack(*sptr_top)){
        MALLOC(temp, stack_element, sizeof(stack_element));
        temp -> val = val;
        temp -> link = *sptr_top;
        *sptr_top = temp;
    }

}

stack_element pop(stack_ptr *sptr_top)      // Parameter is consider as the stack's top.
{
    stack_ptr temp = NULL;
    stack_ptr prev_top = *sptr_top;        // Save the address where to free.

    if(!isEmptyStack(*sptr_top, 0)){
        MALLOC(temp, stack_element, sizeof(stack_element));     // Create stack element to copy.
        temp -> val = (*sptr_top) -> val;
        temp -> link = (*sptr_top) -> link;
        *sptr_top = (*sptr_top) -> link;
        free(prev_top);
    }
    
    return *temp;
}

