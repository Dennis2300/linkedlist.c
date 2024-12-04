// linklist.h
#ifndef LINKLIST_H
#define LINKLIST_H

// Definition af struct for en node.
// Represents a node in the doubly linked list, containing pointers to the next and previous nodes and an integer data field.
typedef struct Node {
    struct Node* nextNode;
    struct Node* prevNode;
    int data;
} Node;

// Definition af struct for en dobbelthægtet liste.
// Represents the doubly linked list itself, containing pointers to the head and tail nodes.
typedef struct LinkList {
    Node* head;
    Node* tail;
} LinkList;

// Function declarations.
LinkList* createLinkList();
Node* createNode(int data);
void appendNode(LinkList* list, int data);
void prependNode(LinkList* list, int data);
void deleteNode(LinkList* list, Node* node);
void printList(LinkList* list);
void freeList(LinkList* list);

#endif
