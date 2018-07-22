//
//  main3.c
//  180504_experimentation
//
//  Created by Ji Hong Guen on 5/11/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void display(ListNode *head);
ListNode* merge(ListNode *head1, ListNode *head2);

void main()
{

    ListNode *head1, *head2;
    head1 = NULL;
    head2 = NULL;

    ListNode *p1;
    p1 = (ListNode *)malloc(sizeof(ListNode));
    p1 -> data = 1;
    p1 -> link = NULL;
    head1 = p1;

    ListNode *p2;
    p2 = (ListNode *)malloc(sizeof(ListNode));
    p2 -> data = 3;
    p2 -> link = NULL;
    p1 -> link = p2;

    ListNode *p3;
    p3 = (ListNode *)malloc(sizeof(ListNode));
    p3 -> data = 4;
    p3 -> link = NULL;
    p2 -> link = p3;

    ListNode *p4;
    p4 = (ListNode *)malloc(sizeof(ListNode));
    p4 -> data = 2;
    p4 -> link = NULL;
    head2 = p4;

    ListNode *p5;
    p5 = (ListNode *)malloc(sizeof(ListNode));
    p5 -> data = 5;
    p5 -> link = NULL;
    p4 -> link = p5;

    ListNode *p6;
    p6 = (ListNode *)malloc(sizeof(ListNode));
    p6 -> data = 8;
    p6 -> link = NULL;
    p5 -> link = p6;

    printf("list1\n");

}

void display(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        printf("%d -> ", p -> data);
        p = p -> link;
    }
    printf("\n");

}

ListNode* merge(ListNode *head1, ListNode *head2)
{
    ListNode *p1, *p2, *Tp, *Nhead;     // Tp == Temp pointer... (Where to link)
    Nhead = NULL;
    Tp = NULL;

    p1 = head1;
    p2 = head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (Nhead == NULL)
        {
            if (p1 -> data <= p2 -> data)
            {
                Nhead = p1;
                Tp = Nhead;
                p1 = p1 -> link;
            }
            else if (p1 -> data > p2 -> data)
            {
                Nhead = p2;
                Tp = Nhead;
                p2 = p2 -> link;
            }
        }

        else
        {
            if (p1 -> data <= p2 -> data)
            {
                Tp -> link = p1;
                Tp = p1;
                p1 = p1 -> link;
            }
            else if (p1 -> data > p2 -> data)
            {
                Tp -> link = p2;
                Tp = p2;
                p2 = p2 -> link;
            }
        }

    } // while

    Tp -> link = NULL;
    display(Nhead);

    if (p1 != NULL) {
        Tp->link = p1;
    }
    else if (p2 != NULL) {
        Tp->link = p2;
    }

    return Nhead;

}
