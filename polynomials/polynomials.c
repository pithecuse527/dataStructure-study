//
//  polynomials.c
//  polynomials
//
//  Created by Ji Hong Guen on 2018. 4. 6..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define COMPARE(a,b) (a < b) ? -1 : (a == b) ? 0 : -1
#define MAX_TERMS 100

void padd(int, int, int, int, int*, int*);  //조교님께 여쭈어보기
void attach(float, int);

int avail = 0;

typedef struct {
    float coef;     // 계수
    int expon;      // 지수
} polynomial;

polynomial terms[MAX_TERMS];

void attach(float coefficient, int exponent)
{
    if(avail >= MAX_TERMS)
    {
        fprintf(stderr, "다항식에 항이 너무 많음.");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    float coefficient;
    *startD = avail;
    while(startA <= finishA && startB <= finishB)
        switch (COMPARE(terms[startA].expon, terms[startB].expon)){
            case -1:
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
                break;
            case 0:
                coefficient = terms[startA].coef + terms[startB].coef;
                if (coefficient)
                    attach(coefficient, terms[startA].expon);
                startA++;
                startB++;
                break;
            case 1:
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
        }

    for(; startA <= finishA; startA++)
        attach(terms[startA].coef, terms[startA].expon);
    for(; startB <= finishB; startB++)
        attach(terms[startB].coef, terms[startB].expon);

    *finishD = avail-1;
}

