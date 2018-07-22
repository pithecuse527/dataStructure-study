//
//  sortAlg.c
//  DateStructure
//
//  Created by Ji Hong Guen on 2018. 3. 14..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x,y) ((x<y) ? -1: ((x==y) ? 0 : 1))

void selection_sort(int [], int);
void selection_list(int [], int);
int sequential_search(int [], int, int);
int binary_search(int [], int, int);

/*
int main(void){

    int n,what;
    int list[MAX_SIZE];

    printf("배열의 크기 : ");
    scanf("%d", &n);

    selection_sort(list, n);
    printf("\n");

    printf("찾고자 하는 수 입력 : ");
    scanf("%d", &what);

    int find1 = sequential_search(list, what, n);
    int find2 = binary_search(list, what, n);

    printf("\n");

    printf("seq_serch 결과 : %d번째에 있다.\n", 1 + find1);
    printf("bin_search 결과 : %d번째에 있다.\n", 1 + find2);
    printf("\n");

}
*/
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

}

int sequential_search(int list[], int search_num, int n){

    for(int i=0; i<n; i++){
        if(list[i] == search_num)
            return i;
    }

    return -1;

}

int binary_search(int list[], int search_num, int n){

    int left = 0, right = n - 1;
    int mid;

    while (left <= right){
        mid = (left + right) / 2;

        switch(COMPARE(list[mid], search_num)){

            case -1 : left = mid + 1;
                break;
            case 0 : return mid;
            case 1 : right = mid - 1;
                break;

        }
    }
    return -1;

}

