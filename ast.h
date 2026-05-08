#ifndef AST_H
#define AST_H

typedef struct Node {
    char name[50];
    char value[100];
    int line;
    struct Node *children[10];
    int child_count;
} Node;

#endif
