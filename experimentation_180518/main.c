//
//  main.c
//  experimentation_180518
//
//  Created by Ji Hong Guen on 5/18/18.
//  Copyright © 2018 Ji Hong Guen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct Node{
    element data;
    struct Node *left;
    struct Node *right;
} Node;

void PreOrderPrintTree(Node* node);
void InOrderPrintTree(Node* node);
void PostOrderPrintTree(Node* node);

int main(int argc, const char * argv[]) {

    Node *root;
    root = (Node *)malloc(sizeof(Node));

    Node *tree7;
    tree7 = (Node *)malloc(sizeof(Node));
    tree7 -> data = 'G';
    tree7 -> left = NULL;
    tree7 -> right = NULL;

    Node *tree6;
    tree6 = (Node *)malloc(sizeof(Node));
    tree6 -> data = 'F';
    tree6 -> left = NULL;
    tree6 -> right = NULL;

    Node *tree5;
    tree5 = (Node *)malloc(sizeof(Node));
    tree5 -> data = 'E';
    tree5 -> left = NULL;
    tree5 -> right = NULL;

    Node *tree4;
    tree4 = (Node *)malloc(sizeof(Node));
    tree4 -> data = 'D';
    tree4 -> left = NULL;
    tree4 -> right = NULL;

    Node *tree3;
    tree3 = (Node *)malloc(sizeof(Node));
    tree3 -> data = 'C';
    tree3 -> left = tree6;
    tree3 -> right = tree7;

    Node *tree2;
    tree2 = (Node *)malloc(sizeof(Node));
    tree2 -> data = 'B';
    tree2 -> left = tree4;
    tree2 -> right = tree5;

    Node *tree1;
    tree1 = (Node *)malloc(sizeof(Node));
    tree1 -> data = 'A';
    tree1 -> left = tree2;
    tree1 -> right = tree3;

    root = tree1;

    PreOrderPrintTree(root);
    printf("\n");
    InOrderPrintTree(root);
    printf("\n");
    PostOrderPrintTree(root);
    printf("\n");

}

void PreOrderPrintTree(Node* node)
{
    if (node == NULL)
        return;

    printf(" %c", node->data);
    PreOrderPrintTree(node->left);
    PreOrderPrintTree(node->right);
}

void InOrderPrintTree(Node* node)
{
    if (node == NULL)
        return;

    InOrderPrintTree(node->left);
    printf(" %c", node->data);
    InOrderPrintTree(node->right);
}

void PostOrderPrintTree(Node* node)
{
    if (node == NULL)
        return;

    PostOrderPrintTree(node->left);
    PostOrderPrintTree(node->right);
    printf(" %c", node->data);
}
