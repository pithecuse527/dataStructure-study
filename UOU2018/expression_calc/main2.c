//
//  main2.c
//  expression_calc
//
//  Created by Ji Hong Guen on 6/7/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPR_SIZE 100
#define MAX_STACKS 50
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }

typedef enum precedence {lparen, rparen, plus, minus,
    times_, divide, mod, eos, operand }precedence;

typedef struct stack_element{
    int val;
    struct stack_element *link;
}stack_element;

typedef struct stack_element *stack_ptr;

stack_element eval(char expr[]);
precedence getToken(char expr[], char *symbol, int *n);

stack_element* initStack(void);
void push(int val, stack_ptr sptr);
stack_element pop(stack_ptr sptr);
void isFullStack(stack_ptr sptr);
void isEmptyStack(stack_ptr sptr);

int main()
{
//
//    stack_ptr sptr1;           // 전체 스택을 가리키는 sptr 선언이자 새로운 스택 덩어리 생성
//    sptr1 = initStack();


    char expr[MAX_EXPR_SIZE] = "123*+ ";
    stack_element result;
    result = eval(expr);

//    push(155, sptr1);
//    push(999, sptr1);
//
//    pop(sptr1);
//    pop(sptr1);



}

stack_element eval(char expr[])
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;

//    stack_element *stack;
//    MALLOC(stack, sizeof(stack_element));
//    stack -> val = NULL;
//    stack -> link = NULL;
    stack_ptr sptr1;
    sptr1 = initStack();

    token = getToken(expr, &symbol, &n);
    while(token != eos){
        if(token == operand) push(symbol-'0', sptr1);
        else{
            op1 = pop(sptr1).val;
            op2 = pop(sptr1).val;
            switch(token){
                case plus: push(op1+op2, sptr1);
                            break;
                case minus: push(op1-op2, sptr1);
                            break;
                case times_: push(op1*op2, sptr1);
                            break;
                case divide: push(op1/op2, sptr1);
                            break;
                case mod: push(op1 % op2, sptr1);
            }
        }
        token = getToken(expr, &symbol, &n);
    }
    return *(sptr1 -> link);
}

precedence getToken(char expr[], char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch(*symbol)
    {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times_;
        case '%' : return mod;
        case ' ' : return eos;
        default : return operand;
    }
}

stack_element* initStack(void)
{
    stack_ptr temp;
    MALLOC(temp, sizeof(stack_element));
    temp -> val = NULL;
    temp -> link = NULL;

    return temp;
}

void push(int val, stack_ptr sptr)
{
    stack_ptr temp;
    MALLOC(temp, sizeof(stack_element));
    isFullStack(sptr);

    temp -> val = val;
    temp -> link = NULL;
    for(; sptr -> link != NULL; sptr = sptr -> link);
    sptr -> link = temp;
}

stack_element pop(stack_ptr sptr)
{
    stack_ptr temp;
    MALLOC(temp, sizeof(*temp));
    isEmptyStack(sptr);

    if(sptr -> link == NULL){           // 스택이 1개 뿐인 경우
        temp -> val = sptr -> val;
        temp -> link = NULL;
        //printf("%d \n", temp -> val);

        sptr -> val = 0;
        sptr -> link = NULL;
    }
    else{
        for(; (sptr -> link) -> link != NULL; sptr = sptr -> link);
        // 연결 스택들 중 다음 스택이 top인 경우 그 이전 스택을 가져옴(sptr).
        temp -> val = sptr -> link -> val;              // 스택 copy 과정 (free 하기 전 복사)
        temp -> link = NULL;

        //printf("%d \n", temp -> val);
        free(sptr -> link);
        sptr -> link = NULL;
    }
    return *temp;
}

void isFullStack(stack_ptr sptr)
{
    int count = 1;
    for(; sptr -> link != NULL; sptr = sptr -> link) count++;
    if (count == MAX_STACKS){               // If stack is full
        fprintf(stderr, "Stack is full!\n");
        exit(EXIT_FAILURE);
    }

}

void isEmptyStack(stack_ptr sptr)
{
    if(sptr -> link == NULL){
        fprintf(stderr, "Stack is Empty!\n");
        exit(EXIT_FAILURE);
    }
}









