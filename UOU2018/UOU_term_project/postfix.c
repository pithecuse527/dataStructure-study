//
//  postfix.c
//  UOU_term_project
//
//  Created by Ji Hong Guen on 6/12/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.c"
#define MAX_EXPR_SIZE 50
#define MALLOC(p, t, s)  if( !(p = (t*)malloc(s))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0};    // In-stack precedence.
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0};   // Incoming precedence.

//extern stack_ptr initStack(void);
extern void push(precedence val, stack_ptr *sptr_top);
extern stack_element pop(stack_ptr *sptr_top);
extern int isFullStack(stack_ptr sptr);
extern int isEmptyStack(stack_ptr sptr, int reason);

char* postfix(char expr[]);                                 // Change infix expression to postfix expression.
precedence getToken(char expr[], char *symbol, int *n);     // Change symbol to token and returns.
char getOperator(precedence token);                         // Change token to symbol and returns.

char* postfix(char expr[])
{
    precedence token;
    char symbol;        // The character from the expression.
    int n = 0;          // Where to get from the expression.

    //char postfix_expr[MAX_EXPR_SIZE];      // This can't be used since it is terminated when function ends.
    char *postfix_expr;
    MALLOC(postfix_expr, char, sizeof(char)* MAX_EXPR_SIZE);   // Create array to save.
    int m = 0;

    //stack_ptr sptr1 = initStack();  // Create stack & Initiation.
    stack_ptr sptr1 = NULL;

    for(token = getToken(expr, &symbol, &n); token != eos; token = getToken(expr, &symbol, &n)){
//        if (token == operand){
//            postfix_expr[m++] = symbol;
//        }

        while(token == operand){
            postfix_expr[m++] = symbol;
            token = getToken(expr, &symbol, &n);
        }

        if(m != 0 && postfix_expr[m-1] != ' ')          // To delimite.
            postfix_expr[m++] = ' ';

        if (token == rparen){
            while(sptr1 -> val != lparen){
                if(!sptr1)   // It reaches the end of it's stack.
                    isEmptyStack(sptr1 -> link, 1);
                postfix_expr[m++] = getOperator(pop(&sptr1).val);

                if(m != 0 && postfix_expr[m-1] != ' ')      // To delimite.
                    postfix_expr[m++] = ' ';
            }
            pop(&sptr1);        // Pop the lparen.

        }
        else if (token == space);  // Do nothing.
        else {
            while(sptr1 && (isp[sptr1 -> val] >= icp[token])){
                postfix_expr[m++] = getOperator(pop(&sptr1).val);
                if(m != 0 && postfix_expr[m-1] != ' ')      // To delimite.
                    postfix_expr[m++] = ' ';
            }
            push(token, &sptr1);
//((temp1+temp2-temp3)*23)/(num1-num2)

        }

    }
    while(sptr1){
        postfix_expr[m++] = getOperator(pop(&sptr1).val);
        if(m != 0 && postfix_expr[m-1] != ' ')      // To delimite.
            postfix_expr[m++] = ' ';
    }

    return postfix_expr;

}

precedence getToken(char expr[], char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch(*symbol){
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times_;
        case '%' : return mod;
        case '\0' : return eos;
        case ' ' : return space;
        default : return operand;
    }
}

char getOperator(precedence token)
{
    switch(token){
        case lparen : return '(';
        case rparen : return ')';
        case plus : return '+';
        case minus : return '-';
        case divide : return '/';
        case times_ : return '*';
        case mod : return '%';
        case space : return ' ';
        default : return '\0';
    }
}
