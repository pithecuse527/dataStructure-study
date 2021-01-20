#include <stdlib.h>
#include <stdio.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void ToBin(int n)
{
  if(n<2) printf("%d", n);
  else
  {
    ToBin(n / 2);
    printf("%d", n%2);
  }
}

int* ToBin2(int n, int* size)
{
  int *b = (int*)calloc((*size), sizeof(int));
  int i;
  for(i=0; n!=0; i++)
  {
    b[i] = n % 2;
    n /= 2;
    if(n != 0) {
      *size = *size + 1;
      b = realloc(b, sizeof(int)*(*size));
    }
  }

  int t;
  for(i=0; i<(*size)/2; i++)
  {
    SWAP(b[i], b[(*size)-i-1], t);
  }

  return b;
}

int main()
{
  int i, size = 1;
  int *tmp = ToBin2(10, &size);
  for(i=0; i<size; i++){
    printf("%d", tmp[i]);
  }
  printf("\n");
  return 0;
}
