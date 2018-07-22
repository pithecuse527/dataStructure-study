//
//  hanoi_.c
//  experimentation_180406
//
//  Created by Ji Hong Guen on 2018. 4. 6..
//  Copyright © 2018년 Ji Hong Guen. All rights reserved.
//


void hanoi_tower(int n, char from, char tmp, char to)
{
    if ( n==1 )
        printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
    else
    {
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}
