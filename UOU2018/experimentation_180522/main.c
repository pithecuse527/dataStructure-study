//
//  main.c
//  experimentation_180522
//
//  Created by Ji Hong Guen on 5/22/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(mem, size)  if( !(mem = malloc(size))  ){\
                            fprintf(stderr, "Insufficient memory!");\
                            exit(EXIT_FAILURE);\
                            }
                            // mem = malloc(size)     --> This code do not need type conversion...
                            //                            Since the variable mem would be have it's pointer type.

#define COMPARE(a, b) ( (a) > (b) ? -1 : (a) == (b) ? 0 : 1 )
#define MAXSIZE 20

struct node{
    int coef;
    int expo;
    struct node *link;
};

typedef struct node *poly_ptr;
poly_ptr a, b, c;

poly_ptr padd(poly_ptr a, poly_ptr b);
void attach(float coefficient, int exponent, poly_ptr *ptr);
void erasePoly(poly_ptr *ptr);

int main(int argc, const char * argv[])
{

    poly_ptr expression1, expression2, expression3;
    MALLOC(expression1, sizeof(*expression1));          // If you do not know why MALLOC is needed,
    MALLOC(expression2, sizeof(*expression2));          // think about int case...    ex)  int a; int *pa;
    MALLOC(expression3, sizeof(*expression3));          //                                 pa = &a;

    poly_ptr expression4, expression5, expression6;
    MALLOC(expression4, sizeof(*expression4));
    MALLOC(expression5, sizeof(*expression5));
    MALLOC(expression6, sizeof(*expression6));

    expression1 -> coef = 5;
    expression1 -> expo = 2;
    expression1 -> link = expression2;

    expression2 -> coef = 3;
    expression2 -> expo = 1;
    expression2 -> link = expression3;

    expression3 -> coef = 1;
    expression3 -> expo = 0;
    expression3 -> link = NULL;


    expression4 -> coef = 5;
    expression4 -> expo = 2;
    expression4 -> link = expression5;

    expression5 -> coef = 3;
    expression5 -> expo = 1;
    expression5 -> link = expression6;

    expression6 -> coef = 1;
    expression6 -> expo = 0;
    expression6 -> link = NULL;

    poly_ptr startA = expression1;
    poly_ptr startB = expression4;

    poly_ptr c = padd(startA, startB);

}

poly_ptr padd(poly_ptr a, poly_ptr b)
{
    poly_ptr front, rear, temp;
    int sum;
    int count=0;
    MALLOC(rear, sizeof(*rear));
    front = rear;

    while (a && b && count < 100){
        switch (COMPARE(a -> expo, b -> expo)){

            case -1:
                attach(b -> coef, b-> expo, &rear);
                b = b -> link;
                break;

            case 0:
                sum = (a -> coef) + (b -> coef);
                attach(sum, a -> expo, &rear);
                //printf("%d, %d \n", a -> coef, b -> coef);
                a = a -> link;  b = b -> link;
                break;

            case 1:
                attach(a -> coef, a -> expo, &rear);
                a = a -> link;

        } count += 1; printf("count : %d\n",count);
    }
    for(; a; a = a -> link) attach(a -> coef, a -> expo, &rear);        // one of two will be excuted.
    for(; b; b = b -> link) attach(b -> coef, b -> expo, &rear);        // one of two will be excuted.

    rear -> link = NULL;
    temp = front;
    front = front -> link;      // because of the function attach's operation.
    free(temp);

    return front;
}

void attach(float coefficient, int exponent, poly_ptr *ptr)     // poly_ptr *ptr : double pointer
{                                                               // This is because rear itself must be changed.
                                                                // ex) *ptr = temp;
    poly_ptr temp;
    MALLOC(temp, sizeof(temp));
    temp -> coef = coefficient;
    temp -> expo = exponent;
    temp -> link = NULL;

    (*ptr) -> link = temp;        // such as (rear -> link = temp)
    *ptr = temp;

}

void erasePoly(poly_ptr *ptr)       // Delete all terms after the term that is given.
{                                   // If you give the start position of the poly, then the poly will be deleted.
    poly_ptr temp;
    while (*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr) -> link;
        free(temp);
    }

}
