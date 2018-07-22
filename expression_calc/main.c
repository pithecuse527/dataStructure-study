//
//  main.c
//  expression_calc
//
//  Created by Ji Hong Guen on 6/6/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPR_SIZE 100
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }

typedef enum precedence {lparen, rparen, plus, minus,
    times_, divide, mod, eos, operand }precedence;

int stack1[MAX_EXPR_SIZE];
int top = -1;
int eval(char stack[]);
precedence getToken(char stack[], char *symbol, int *n);
void push(int item, char stack[]);
char pop(char stack[]);



typedef struct stack2{
    int sym;
    struct stack2 *link;
    int isTop;
}stack2;
stack2 eval2(stack2 stack);
precedence getToken2(stack2 stack, char *symbol, int *n);
void push2(stack2 stack);
stack2 pop2(stack2 stack);

//char expr[MAX_EXPR_SIZE];
int main(int argc, const char * argv[])
{

    char *expr;
    MALLOC(expr, sizeof(char) * MAX_EXPR_SIZE);
    //char expr[MAX_EXPR_SIZE] = "123*- ";

//    printf("문자열 입력 : ");
//    scanf("%s", expr);
    printf("expr1 : %s\n", expr);

    printf("%d\n", eval(expr));


}



//--------------------------------------------//
//--------------------------------------------//
//--------------------------------------------//



int eval(char stack[])
{
    precedence token;
    char symbol;        // temp variable that contains the character from expression.
    int op1, op2;
    int n = 0;          // counter for the expression.

    token = getToken(stack, &symbol, &n);
    while(token != eos){
        if(token == operand) push(symbol-'0', stack);
        else{
            op2 = pop(stack);
            op1 = pop(stack);
            switch(token){
                case plus: push(op1+op2, stack);
                            break;
                case minus: push(op1-op2, stack);
                            break;
                case times_: push(op1*op2, stack);
                            break;
                case divide: push(op1/op2, stack);
                            break;
                case mod: push(op1 % op2, stack);
            }
        }
        token = getToken(stack, &symbol, &n);

    }
    return pop(stack);
}

precedence getToken(char stack[], char *symbol, int *n)
{
    *symbol = stack[(*n)++];
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

void push(int item, char stack[])
{
    stack[++top] = item;
}

char pop(char stack[])
{
    return stack[top--];
}



