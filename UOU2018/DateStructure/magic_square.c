//
//  magic_square.c
//  DateStructure
//
//  Created by Ji Hong Guen on 2018. 3. 29..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE_1 15
#define MAX_SIZE_2 1001
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void magic_square(void);
void selection_sort(int [], int);
void sel_sort_time(void);

int main(void)
{
    sel_sort_time();
}

void magic_square(void){

    int static square[MAX_SIZE_1][MAX_SIZE_1];
    int i, j, row, col;
    int count;
    int size;

    printf("Enter the size of the square: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE_1 + 1)
    {
        fprintf(stderr, "Error! Size is out of range\n");
        exit(1);
    }

    if (!size % 2){
        fprintf(stderr, "Error! Size is even\n");
        exit(1);
    }

    for (i = 0; i < size; i ++)
        for (j = 0; j < size; j++)
            square[i][j] = 0;

    square[0][(size-1)/2] = 1;

    i = 0;
    j = (size-1)/2;
    for (count = 2; count <= size * size; count++) {
        row = (i-1 < 0) ? (size - 1): (i - 1);
        col = (j-1 < 0) ? (size - 1) : (j - 1);
        if (square[row][col])
            i = (i+1) % size;
        else {
            i = row;
            j = col;
        }
        square[i][j] = count;
    }

    printf("Magic Square of size %d : \n\n",size);
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++)
            printf("%5d", square[i][j]);
        printf("\n");
    }
}

void selection_sort(int list[], int n){

    int min,temp;

    for (int i=0; i<n; i++){
        printf("%d번째 배열의 값 : ", i+1);
        scanf("%d", &list[i]);
    }

    printf("\n정렬 전 배열 : ");
    for (int i=0; i<n; i++){
        printf("%d ", list[i]);
    }

    for (int i=0; i < n-1; i++){

        min = i;

        for(int j=i+1;j < n; j++)
            if(list[j] < list[min])
                min = j;
        SWAP(list[i], list[min], temp);
    }

    printf("\n정렬 후 배열 : ");
    for (int i=0; i<n; i++){
        printf("%d ", list[i]);
    }

    printf("\n");

}


void sel_sort_time(void){

    int i, n, step = 10;
    int a[MAX_SIZE_2];
    double duration;
    clock_t start;

    printf("\n");
    for(n=0; n <= 1000; n +=step)
    {
        for (i=0; i < n; i++)
            a[i] = n - i;

        start = clock();
        selection_sort(a,n);
        duration = ((double)(clock() - start));

        printf("%6d   %f\n", n, duration);
        if (n == 100)
            step = 100;
    }

}
