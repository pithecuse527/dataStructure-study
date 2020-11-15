//
//  main.c
//  UOU_term_project
//
//  Created by Ji Hong Guen on 6/12/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "common.c"

extern char* postfix(char expr[]);
extern char* inputExpression(void);
char* inputExpression(void);          // Take expression from user's input.

int main()
{
    char *expr = inputExpression();
    printf("\nThis is the infix expression.\n");
    printf("%s\n\n", expr);

    char *postfix_expr1 = postfix(expr);
    printf("This is the postfix expression.\n");
    printf("%s\n\n", postfix_expr1);

}

char* inputExpression()
{
    char *expr;
    MALLOC(expr, char, sizeof(char) * MAX_EXPR_SIZE);
    printf("Type the infix expression.\n");
    scanf("%[^\n]s",expr);

    return expr;
}
