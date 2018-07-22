//
//  main.c
//  180504_experimentation
//
//  Created by Ji Hong Guen on 5/4/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
    if(!((p) = malloc(s))) { \
        fprintf(stderr, "Insufficient memory!"); \
        exit(EXIT_FAILURE); \
    }

typedef struct listNode *listPointer;

typedef struct listNode {
    int data;
    listPointer link;
} listNode;

listNode *head, *head_1;


void insert(listPointer *first, listPointer x);
void delete(listPointer *first, listPointer trail, listPointer x);
void printList(listPointer first);
void printCirList(listPointer first);

listNode *concat(listNode *head1, listNode *head2);
//void merge(listNode* head1,listNode *head2, listNode* newhead);

int main(int argc, const char * argv[]) {

    listPointer first, second, third, fourth;

    first = (listNode *) malloc(sizeof(listNode));
    first -> data = 1;

    second = (listNode *) malloc(sizeof(listNode));
    second -> data = 3;

    third = (listNode *) malloc(sizeof(listNode));
    third -> data = 5;

    fourth = (listNode *) malloc(sizeof(listNode));
    fourth -> data = 7;


    first -> link = second;
    second -> link = third;
    third -> link = fourth;
    fourth -> link = first;

    listNode *first_list;
    first_list = (listNode*)malloc(4 * sizeof(listNode));

    first_list[0] = *first;
    first_list[1] = *second;
    first_list[2] = *third;
    first_list[3] = *fourth;
    head = first;


    listPointer first_1, second_1, third_1, fourth_1;

    first_1 = (listNode *) malloc(sizeof(listNode));
    first_1 -> data = 2;

    second_1 = (listNode *) malloc(sizeof(listNode));
    second_1 -> data = 4;

    third_1 = (listNode *) malloc(sizeof(listNode));
    third_1 -> data = 6;

    fourth_1 = (listNode *) malloc(sizeof(listNode));
    fourth_1 -> data = 8;

    first_1 -> link = second_1;
    second_1 -> link = third_1;
    third_1 -> link = fourth_1;
    fourth_1 -> link = first_1;




    listNode *first_list_1;
    first_list_1 = (listNode*)malloc(4 * sizeof(listNode));

    first_list_1[0] = *first_1;
    first_list_1[1] = *second_1;
    first_list_1[2] = *third_1;
    first_list_1[3] = *fourth_1;
    head_1 = fourth_1;


//    for(int i=0; i<4; i++)
//    {
//        printf("%d ", first_list[i].data);
//    }
//
//    printf("\n\n");
//
//    for(int i=0; i<4; i++)
//    {
//        printf("%d ", first_list_1[i].data);
//    }

    printf("\n\n");

    concat(head, first_1);

    printCirList(head);

    listNode *p = first;

    listNode *new_list;
    new_list = (listNode*)malloc(8 * sizeof(listNode));

    for(int i=0; i<8; i++)
    {
        new_list[i] =
        p = p -> link;
    }


    //printCirList(first_1);


}


listNode *concat(listNode *head1, listNode *head2)
{
    listNode *p;
    if( head1 == NULL ) return head2;
    else if( head2 == NULL ) return head1;
    else {
        p = head1;
        while( p->link != head1 )
            p = p->link;
        p->link = head2;

        return head1;
    }

}

//void merge(listNode *head1, listNode *head2, listNode* newhead)
//{
//    listNode *p;
//    p = head1;
//    while( p->link != NULL )
//        p = p->link;
//    p->link = head2;
//
//}

//
//int main(int argc, const char * argv[]) {
//
//    listPointer first, second, third, fourth;
//
//    first = (listNode *) malloc(sizeof(listNode));
//    strcpy(first -> data, "sat");
//
//    second = (listNode *) malloc(sizeof(listNode));
//    strcpy(second -> data, "cat");
//
//    third = (listNode *) malloc(sizeof(listNode));
//    strcpy(third -> data, "mat");
//
//    fourth = (listNode *) malloc(sizeof(listNode));
//    strcpy(fourth -> data, "bat");
//
//    first -> link = second;
//    second -> link = third;
//    third ->  link = fourth;
//    fourth -> link = first;
//
//    head = fourth;
//
//    printCirList(first);
//
//}
//
void printCirList(listPointer first)
{
    printf("The list contains : ");
    for (; first; first = first -> link)
    {
        printf("%d ", first->data);
        if (first -> link == head_1)
        {
            first = first -> link;
            printf("%d ", first->data);
            printf("\n");
            return;
        }
    }

}
//
//void printList(listPointer first)
//{
//    printf("The list contains : ");
//    for (; first; first = first -> link)
//        printf("%s", first->data);
//    printf("\n");
//}
///*
//void create2()
//{
//
//    listPointer first, second;
//    MALLOC(first, sizeof(listNode));
//    MALLOC(second, sizeof(listNode));
//
//    strcpy(second -> data, "sat");
//    second -> link = NULL;
//
//    strcpy(first -> data, "cat");
//    first -> link = second;
//
//    //return first;
//
//}
//*/
//void insert(listPointer *first, listPointer x)
//{
//    listPointer temp;
//    MALLOC(temp, sizeof(listPointer));
//
//    //temp -> data = 50;
//
//    if(*first)
//    {
//        temp -> link = x -> link;
//        x -> link = temp;
//    }
//    else {
//        temp -> link = NULL;
//        *first = temp;
//    }
//
//}
//
//void delete(listPointer *first, listPointer trail, listPointer x)
//{
//    if(trail)
//        trail -> link = x -> link;
//    else
//        *first = (*first) -> link;
//    free(x);
//}
//
//

