//
//  main.c
//  experimentation_180406
//
//  Created by Ji Hong Guen on 2018. 4. 6..
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//extern void hanoi_tower(int n, char from, char tmp, char to)

int factorial(int n);
double power(double, int);
int fib_iter(int, int[]);
int fib(int);
void fib_3(int[], int);
void fib_2(int, int, int, int);

int count = 0;
int tmp;
int tmp2;

int main(int argc, const char * argv[]) {



    int n;
    //    float x;

    printf("\n3.피보나치 수열 알고리즘\n");
    printf("f(n)에서 n의 값을 입력하시오 : ");
    scanf("%d", &n);

    int fibo[n];
    fib_3(fibo, n);

    /*
    printf("팩토리얼 알고리즘\n몇팩? ");
    scanf("%d", &n);
    printf("%d! = %d\n", n,factorial(n));

    printf("\n2.거듭제곱 알고리즘\n");
    printf("x의 값? (x^n) ");
    scanf("%f", &x);
    printf("n의 값? (x^n) ");
    scanf("%d", &n);
    printf("%.2f^? = %.2f\n", x, power(x,n));
    printf("반복횟수는 %d회 입니다.\n", count);

     */


//    printf("fib함수\n");
//    for(int j=1; j<n; j++)
//    {
//        printf("%d ", fib(j));
//    }
//    printf("\n");
//
//    printf("\nfib_iter함수\n");
//    //int *parr = (int(*)[])malloc(sizeof(int) * n);
//
//    int parr[n];
//    for(int j=0; j<n; j++)
//        parr[j] = 0;
//
//    fib_iter(n, parr);
//
//    for(int j=0; j < n-1; j++)
//    {
//        printf("%d ", *(parr + j));
//    }
//    printf("\n");


}


int factorial(int n)
{

    if(n <= 1)
        return 1;
    else
        return(n * factorial(n-1));
}
/*
double power(double x, int n)
{
    count++;

    if( n == 1 )
        return x;
    else if( n == 0 )
        return 1;
    else
        return x*power(x, n-1);
}

int fib_iter(int n, int arr[])
{
    if( n < 2)
        return n;
    else
    {
        int i;
        for(i=0; i<=1; i++ )
            arr[i] = 1;

        for(i=2; i<=n; i++)
            arr[i] = arr[i-1] + arr[i-2];
    }
    return 0;
}

int fib(int n)
{

    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    return (fib(n-1) + fib(n-2));

}


void fib_2(int n2, int n1, int i, int n)
{
    int tmp;
    if (i >= n) return;
    else if ( i == 2) printf("0 1");
    tmp = n2 + n1;
    printf(" %d", n2 + n1);
    fib_2(n1, tmp, ++i, n);
}

*/


// 함수 호출 시 배열과 인덱스 갯수만 전달하여 피보나치 수열을 출력함.
// 전역변수 tmp을 이용하여 1을 fibo[0], fibo[1]에 저장함.
// 나머지 값들은 전역변수 tmp2를 이용하여 저장함.
// 여기서 전역변수 tmp, tmp2를 쓰는것 보다 더 좋은 방법이 있을 것 같지만 딱히 방법이 생각나지 않음.

void fib_3(int fibo[], int n)
{
    if (tmp == 0)
        tmp = n;                // if global variable tmp is null
    if ((n - 2) < tmp)          // for print fibo[0], fibo[1]
    {
        fibo[n % 10] = 1;
        printf("%d ", fibo[n % 10]);
        fib_3(fibo, n+1);
    }
    else if (n >= tmp && n < tmp*2)     // (tmp <= n < tmp*2)
    {
        tmp2 = (n % tmp);

        //printf("\n%d, %d, %d %d ",tmp , n,tmp2, fibo[(tmp2-2)]);

        fibo[tmp2] = fibo[(tmp2-2)] + fibo[(tmp2-1)];   //      same as fibo[a] = fibo[a-1]+fibo[a-2]
        printf("%d ", fibo[tmp2]);
        fib_3(fibo ,n+1);
    }
    else                    // if n >= tmp*2
    {
        printf("\n");
        return;
    }

}
