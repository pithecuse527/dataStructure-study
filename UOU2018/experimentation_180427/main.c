//
//  main.c
//  experimentation_180427
//
//  Created by Ji Hong Guen on 4/27/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element list[MAX_LIST_SIZE];
    int length;
}ArrayListType;

void init(ArrayListType *L);
int is_empty(ArrayListType *L);
int is_full(ArrayListType *L);
void add(ArrayListType *L, int position, element item);
element delete(ArrayListType *L, int position);
void replace(ArrayListType *L, int position, element item);
void add_first(ArrayListType *L, element item);
void add_last(ArrayListType *L, element item);
int get_pos(ArrayListType *L, element item);
int is_in_list(ArrayListType *L, element item);
element get_entry(ArrayListType *L, element pos);
void display(ArrayListType *L);


int main(int argc, const char * argv[])
{

    ArrayListType list1;
    init(&list1);

    list1.list[0] = 'a';
    list1.list[1] = 'b';
    list1.list[2] = 'c';
    list1.list[3] = 'd';
    list1.length = 4;

    add(&list1, 1, 'e');
    replace(&list1, 2, 'f');
    add_first(&list1, 'g');
    add_last(&list1, 'h');
    delete(&list1, get_pos(&list1, 'c'));

}

void init(ArrayListType *L)
{
    L -> length = 0;
}

int is_empty(ArrayListType *L)
{
    return L -> length == 0;

}

int is_full(ArrayListType *L)
{
    return L -> length == MAX_LIST_SIZE;
}

void add_first(ArrayListType *L, element item)
{
    int i;
    if( !is_full(L) )
       for(i = (L -> length-1); i >= 0; i--)
            L->list[i+1] = L->list[i];
    L -> list[0] = item;
    L -> length++;
}

void add_last(ArrayListType *L, element item)
{
    int len = L -> length;
    if (!is_full(L))
       L -> list[len] = item;
    L->length++;
}

void add(ArrayListType *L, int position, element item)
{
    if( !is_full(L) && (position >= 0) && (position <= L->length) ){
        int i;
        for(i = (L -> length - 1); i>= position; i--)
            L->list[i+1] = L->list[i];
        L->list[position] = item;
        L->length++;

    }
}

void replace(ArrayListType *L, int position, element item)
{

    if( (position >= 0) && (position <= L -> length) )
        L -> list[position] = item;
    else
        exit(EXIT_FAILURE);

}

element delete(ArrayListType *L, int position)
{
    int i;
    element item;

    if( position < 0 || position >= L -> length )
    {
        exit(EXIT_FAILURE);
    }
    item = L->list[position];
    for(i = position; i < (L -> length-1); i++)
        L -> list[i] = L -> list[i+1];
    L->length--;

    return item;
}

int get_pos(ArrayListType *L, element item)
{
    int i=0;

    for(i=(L -> length-1); i >= 0; i--)
        if (L -> list[i] == item)
            return i;

    return -1;
}

int is_in_list(ArrayListType *L, element item)
{
    int i;
    for(i=(L -> length-1); i>=0; i--)
        if (L -> list[i] == item)
            return 1;
    return 0;
}

element get_entry(ArrayListType *L, element pos)
{
    if (L -> list[pos])
        return L -> list[pos];
    return -1;
}

void display(ArrayListType *L)
{
    for (int i=0; i< L -> length; i++)
        printf("%c ", L -> list[i]);
    printf("\n");
}
