//
//  transpose.c
//  playGround
//
//  Created by Ji Hong Guen on 4/20/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#define MAX_COL 100

typedef struct{
    int row;
    int col;
    int val;
} term;


void transpose(term a[], term b[])
{

    int n, i, j, currentb;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    n = a[0].val;

    if(n > 0)
    {
        currentb = 1;
        for (i=0; i < a[0].col; i++)
            for (j=1; j <= n; j++)
                if (i == a[j].col)
                {
                    b[j].row = a[j].col;
                    b[j].col = a[j].row;
                    b[j].val = a[j].val;
                    currentb++;
                }
    }

    // Big-Oh( a[0].col * a[0].val )

}

void fast_transpose(term a[], term b[])
{

    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i,j, numCols = a[0].col, numTerms = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;

    if (numTerms > 0)
    {
        for (i = 0; i < numCols; i++)
            startingPos[i] = 0;
        for (i = 1; i < numCols; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        for (i = 1; i < numTerms; i++)
        {
            j = startingPos[a[i].col]++;
            b[j].col = a[i].row;
            b[j].row = a[i].col;
            b[j].val = a[i].val;
        }
    }

}


int main(int argc, const char * argv[]){



}

