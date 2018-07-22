//
//  main.c
//  Extra_proj
//
//  Created by Ji Hong Guen on 2018. 3. 23..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 100

void prime_num(int[], int);

int main(int argc, const char * argv[]) {

    int is_prime[MAX_SIZE];
    int n = MAX_SIZE;

    for (int i=0; i < 100; i++){
        is_prime[i] = 1;
    }

   prime_num(is_prime, n);

    for (int i=1; i < 100; i++){

    }// isprime??

    printf("\n");

}

void prime_num(int is_prime[], int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if (i % j == 0){
                is_prime[i] = 0;
            }
        }
    } //for

}
