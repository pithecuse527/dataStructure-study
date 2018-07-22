//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Node {     // 여기 무엇?
//    char data[4];
//    struct Node *link;
//} Node;
//
//Node *head = NULL, *temp;
//
//Node create(char *x)
//{
//    temp = (Node*)malloc(sizeof(Node));
//    strcpy(temp->data, x);
//    temp->link = NULL;
//    //head = temp;
//
//    return *head;
//}
//
//void insertion(char *x, char *y)
//{
//    Node *ptr = head;
//
//    while(ptr)
//    {
//        if(strcmp(ptr->data, x) == 0) break;
//        ptr = ptr -> link;
//    }
//
//    if(!ptr)
//    {
//        printf("찾는 문자열 없음\n");
//        exit(1);
//    }
//    temp = (Node *)malloc(sizeof(Node));
//    strcpy(temp -> data,y);
//    temp -> link = ptr -> link;
//    ptr -> link = temp;
//}
//
//void deletion(char *x)
//{
//    Node *ptr = head;
//    Node *previous = head;
//
//    while(ptr)
//    {
//        if(strcmp(ptr -> data, x) == 0) break;
//        previous = ptr;
//        ptr = ptr -> link;
//    }
//
//    if(!ptr)
//    {
//        printf("찾는 문자열 없음\n");
//        exit(1);
//    }
//
//    previous -> link = ptr -> link;
//    free(ptr);
//}
//
//
//
