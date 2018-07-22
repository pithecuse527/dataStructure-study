//
//  main.c
//  experimentation_180413
//
//  Created by Ji Hong Guen on 4/12/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TERMS 100
#define MAX_COL 100
#define MAX_DEGREE 101
#define MAX(x, y) x < y ? y : x
#define COMPARE(x, y) x < y ? -1 : x == y ? 0 : 1

/* ------------------------------- */

typedef struct {
    float coef;     // 계수
    int expo;       // 지수
} poly;

typedef struct {
    int degree;                 // 차수
    float coef[MAX_DEGREE];     // 계수
} poly2;

void main_poly(void);
void padd(int, int, int, int, int*, int*);
poly2 padd2(poly2, poly2);
void attach(float, int);

poly terms[MAX_TERMS];
poly2 terms2;
int avail = 0;

/* ------------------------------- */

typedef struct {
    int row;
    int col;
    int val;
} term;

void main_sparse(void);
void transpose(term[], term[]);
void fast_transpose(term[], term[]);


term a[MAX_TERMS];

/* ------------------------------- */


int main(int argc, const char * argv[])
{

    main_poly();

}


/* ------------------------------- *//* ------------------------------- *//* ------------------------------- */

void main_poly()
{

//    int i = 0, j, startA, finishA, startB, finishB;
//
//    //avail 사용.
//
//    printf("첫번째 항의 갯수를 입력하세요. ");
//    scanf("%d", &j);
//
//    startA = avail;
//    while(1)
//    {
//
//        printf("지수를 입력하세요. ");
//        scanf("%d", &terms[i].expo);
//        printf("계수를 입력하세요. ");
//        scanf("%f", &terms[i].coef);
//
//        i++;
//
//        if(i >= j) break;
//
//    }
//
//    finishA = i - 1;
//
//
////    for(j = 0; j < i; j++)
////    {
////        printf("=======%d번째 항=======\n", j+1);
////        printf("\n지수 : %d", terms[j].expo);
////        printf("\n계수 : %f\n\n", terms[j].coef);
////    }
//
//    printf("두번째 항의 갯수를 입력하세요. ");
//    scanf("%d", &j);
//
//    while(1)
//    {
//
//        printf("지수를 입력하세요. ");
//        scanf("%d", &terms[i].expo);
//        printf("계수를 입력하세요. ");
//        scanf("%f", &terms[i].coef);
//
//        i++;
//
//        if(i >= j) break;
//
//    }


//    startA = avail;
//
//
//    while(coef != 0)
//    {
//        terms2.degree = (int)expression1[startA+3];
//        terms2.coef[i] = (float)expression1[startA + (2*i)];
//        i++; startA++;
//    }
//
//    if (what==1)
//    {
//
//        printf("%s", padd2(expression1, expression2));
//
//    }



}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finished)
{

    int coeff;

    *startd = avail;
    while (starta <= finisha && startb <= finishb)
        switch(COMPARE(terms[starta].expo, terms[startb].expo))
        {
            case -1 : attach(terms[startb].coef, terms[startb].expo);
                      startb++;
                      break;
            case 0  : coeff = terms[starta].coef + terms[startb].coef;
                      attach(coeff, terms[starta].expo);
                      starta++; startb++;
                      break;
            case 1  : attach(terms[starta].coef, terms[starta].expo);
                      starta++;
        }

    for(; starta <= finisha; starta++)
        attach(terms[starta].coef, terms[starta].expo);
    for(; startb <= finishb; startb++)
        attach(terms[startb].coef, terms[startb].expo);
    *finished = avail - 1;
}


poly2 padd2(poly2 A, poly2 B)
{
    poly2 C;                // 결과 다항식
    int Apos=0, Bpos=0, Cpos=0;    // 배열 인덱스 변수
    int degree_a=A.degree;
    int degree_b=B.degree;
    C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
    while( Apos<=A.degree && Bpos<=B.degree ){
        if( degree_a > degree_b ){ // A항 > B항
            C.coef[Cpos++]= A.coef[Apos++];
            degree_a--;
        }

        else if( degree_a == degree_b ){ // A항 == B항
            C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else {            // B항 > A항
            C.coef[Cpos++]= B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}


void attach(float coef, int expo)
{
    if(avail >= MAX_TERMS)
    {
        fprintf(stderr, "다항식에 항이 너무 많습니다. \n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].expo = expo;
}

/* ------------------------------- *//* ------------------------------- *//* ------------------------------- */

void main_sparse()
{
    int tmp_row, tmp_col, tmp_val=1, count=0;

    printf("만들 행렬의 행과 열을 차례로 입력하시오. ");
    scanf("%d %d", &tmp_row, &tmp_col);


    a[0].row = tmp_row;
    a[0].col = tmp_col;

    int i=1;

    while (tmp_col >= 0 && tmp_row >= 0)
    {
        printf("종료하려면 음수를 입력하시오.\n");
        printf("값을 입력할 행 : ");
        scanf("%d", &tmp_row);
        if(tmp_row >= 0)
        {
            printf("값을 입력할 열 : ");
            scanf("%d", &tmp_col);
        }

        if(tmp_col >= 0 && tmp_row >= 0)
        {
            printf("그 행열에 들어갈 값 : ");
            scanf("%d", &tmp_val);
        }

        if(tmp_col >= 0 && tmp_row >= 0)
        {
            a[i].row = tmp_row;
            a[i].col = tmp_col;
            a[i].val = tmp_val;
            i++;
            count++;
        }
    }

    a[0].val = count;


    for(int i=1; i <= count; i++)
    {
        printf("\n");
        printf("행 : %d\n", a[i].row);
        printf("열 : %d\n", a[i].col);
        printf("값 : %d\n\n", a[i].val);
    }

    term b[MAX_TERMS];
    //transpose(a, b);
    fast_transpose(a, b);

    printf("---------- After transpose! ----------\n");

    for(int i=1; i <= count; i++)
    {
        printf("\n");
        printf("행 : %d\n", b[i].row);
        printf("열 : %d\n", b[i].col);
        printf("값 : %d\n\n", b[i].val);
    }

}

void transpose(term a[], term b[])
{
    int n, i, j, currentb;
    n = a[0].val;
    b[0].row = a[0].col;
    b[0].val = a[0].val;
    b[0].col = a[0].col;

    if(n>0)
    {
        currentb = 1;
        for(i = 0; i < a[0].col; i++)
            for(j = 1; j <= n; j++)
                if(a[j].col == i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].val = a[j].val;
                    currentb++;
                }
    }
}

void fast_transpose(term a[], term b[])
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i,j,numCols = a[0].col, numTerms = a[0].val;

    b[0].row = numCols;
    b[0].col = a[0].row;

    if(numTerms > 0)
    {
        for(i = 0; i < numCols; i++)
            rowTerms[i] = 0;
        for(i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for(i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        for(i = 1; i <= numTerms; i++)
        {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }
}
