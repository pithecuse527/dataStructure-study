//
//  main.c
//  DateStructure
//
//  Created by Ji Hong Guen on 2018. 3. 9..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <locale.h>
#define COMPARE(x,y) ((x<y) ? -1 : ((x==y) ? 0 : 1))
#define SWAP(x,y,t) (t = x, x = y, y=t)

void selection_list(int list[], int n){

    int min, temp;

    for (int i=0; i<n; i++){
        printf("%d번째 배열의 값 : ", i);
        scanf("%d", &list[i]);
    }

    printf("정렬 전 배열 : ");
    for (int i=0; i<n; i++)
        printf("%d", list[i]);

    for (int i=0; i<n; i++){
        min = list[i];
        for (int j=i+1; j<n; j++){
            if (list[j] < min)
                SWAP(list[j], min, temp);
        }
    }

    printf("정렬 후 배열 : ");

    for (int i=0; i<n; i++)
        printf("%d", list[i]);

}

