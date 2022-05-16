#ifndef INCLUDE_NODE_H
#define INCLUDE_NODE_H

typedef struct Node {
    char* data;
    struct Node* prev;
    struct Node* next;
} Node;

#endif
