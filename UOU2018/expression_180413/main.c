//
//  main.c
//  expression_180413
//
//  Created by Ji Hong Guen on 4/13/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

typedef int element;

typedef struct {
    element stack[MAX_SIZE];
    int top;
}StackType;


void init(StackType );
int peek(StackType );
int is_empty(StackType );
int is_full(StackType );
void push(StackType , int);
int pop(StackType , int);

int main(int argc, const char * argv[]) {

    StackType Stack;
    init(Stack);
    int num, x;

    for(int i=0; i < 5; i++)
    {
        printf("push : ");
        scanf("%d", &x);
        push(Stack, x);
    }

    printf("peek : %d\n", peek(Stack));
    printf("pop : ");
    scanf("%d", &num);
    pop(Stack, num);

}

void init(StackType Stack)
{
    Stack.top = -1;
}

int peek(StackType Stack)
{
    return Stack.stack[Stack.top];
}

int is_empty(StackType Stack)
{
    if(Stack.top == -1)
        return 1;
    return 0;
}

int is_full(StackType Stack)
{
    if (*Stack.top == MAX_SIZE-1)
        return 1;
    return 0;
}

void push(StackType Stack, int x)
{
    if(is_full(Stack))
    {
        fprintf(stderr, "Stack is full, cannot add element.");
        exit(EXIT_FAILURE);
    }

    Stack.top += 1;
    Stack.stack[Stack.top] = x;
    printf("%d", Stack.top);

}

int pop(StackType Stack, int x)
{

    if(Stack.top == -1)
    {
        fprintf(stderr, "Stack is empty, cannot pop element.");
        exit(EXIT_FAILURE);
    }

    return Stack.stack[Stack.top--];

}

