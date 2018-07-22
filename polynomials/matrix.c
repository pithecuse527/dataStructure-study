//
//  matrix.c
//  polynomials
//
//  Created by Ji Hong Guen on 2018. 4. 6..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#define MAX_TERMS 101

typedef struct{
    int col;    // 어느 행
    int row;    // 어느 열
    int value;  // 어떤 값
} term;


term a[MAX_TERMS];


void transpose(term a[], term b[])
{
    int n, i, j, currentb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].value = n;
    b[0].col = a[0].row;

    if(n > 0)
    {
        currentb = 1;
        for( i = 0; i < a[0].col ; i++)
            for( j = 1; j <= n; j++)
                if(a[j].col == i)               // 노트에 나온 행렬을 보면 이해할 수 있음 (col의 0부터 5번까지)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
}

// time complexity : Big-Oh(columns * elements)
// if it is not a sparse matrix, then elements is substituted as (rows * columns)
