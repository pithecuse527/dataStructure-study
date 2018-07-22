//
//  postfixing.c
//  expression_calc
//
//  Created by Ji Hong Guen on 6/8/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 50
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                                fprintf(stderr, "Insufficient memory!");\
                                exit(EXIT_FAILURE);\
                                }

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0};
int top;

typedef enum precedence {lparen, rparen, plus, minus,
                        times_, divide, mod, eos, operand }precedence;

typedef struct stack_element{
    precedence val;
    struct stack_element *link;
}stack_element;
typedef struct stack_element *stack_ptr;

precedence getToken(char expr[], char *symbol, int *n);
void postfix(char expr[]);

stack_element* initStack(void);
void push(precedence val, stack_ptr sptr);
stack_element pop(stack_ptr *sptr);
void isFullStack(stack_ptr sptr);
void isEmptyStack(stack_ptr sptr);

precedence stack[25];

int main()
{
    char expr[20] = "(1+2+3) ";

    postfix(expr);
    
    
}

void postfix(char expr[])
{
//    char symbol;
//    precedence token;
//    int n = 0;
//    int top = 0;
//    stack[0] = eos;
//    for(token = getToken(expr, &symbol, &n); token != eos; token = getToken(expr, &symbol, &n))
//    {
//        if (token == operand) printf("%c", symbol);
//        else if (token == rparen){
//            while(stack[top] != lparen); //print&pop();
//        //pop();   // 왼쪽 괄호는 바로 팝
//        }
//        else {
//            while (isp[stack[top]] >= icp[token]);
//                //print&pop();
//            //push(token);
//        }
//    }
//    while ( (token=pop()) != eos);
//        //printpop();
//    printf("\n");

    precedence token;
    char symbol;
    int n = 0;

    stack_ptr sptr1;
    sptr1 = initStack();

    for(token = getToken(expr, &symbol, &n); token != eos; token = getToken(expr, &symbol, &n)){
        if (token == operand) printf("%c", symbol);
        else if (token == rparen){
            //while(sptr1 -> val != lparen) pop(sptr1);
            for( ;sptr1 -> val != lparen; pop(sptr1)) ;
            pop(&sptr1);        // 왼쪽 괄호 갖다 버림
        }
        else{
            //stack_ptr sptr1_top = sptr1;            // 굳이 또 다른 top 포인터가 필요한가..?
            //for(;sptr1_top -> link != NULL; sptr1_top = sptr1_top -> link)
            //while (isp[stack[top]] >= icp[token]);
            while(isp[sptr1 -> val] >= icp[token]) pop(sptr1);
            push(token, sptr1);
        }
    }

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

void push(precedence val, stack_ptr sptr)
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
    stack_ptr temp;             // 복사해서 리턴할 공간 생성
    MALLOC(temp, sizeof(*temp));
    isEmptyStack(sptr);

    if(sptr -> link == NULL){           // 스택이 1개 뿐인 경우
        temp -> val = sptr -> val;
        temp -> link = NULL;
        printf("%d \n", temp -> val);

        sptr -> val = 0;
        sptr -> link = NULL;
    }
    else{
        for(; (sptr -> link) -> link != NULL; sptr = sptr -> link);
        // 연결 스택들 중 다음 스택이 top인 경우 그 이전 스택을 가져옴(sptr).
        temp -> val = sptr -> link -> val;              // 스택 copy 과정 (free 하기 전 복사)
        temp -> link = NULL;

        printf("%d \n", temp -> val);
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



