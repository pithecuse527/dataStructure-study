//
//  common.c
//  UOU_term_project
//
//  Created by Ji Hong Guen on 6/12/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPR_SIZE 50
#define MALLOC(p, t, s)  if( !(p = (t*)malloc(s))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }


typedef enum precedence {lparen, rparen, plus, minus,
    times_, divide, mod, eos, operand , space}precedence;

typedef struct stack_element{
    precedence val;
    struct stack_element *link;
}stack_element;

typedef struct stack_element *stack_ptr;

