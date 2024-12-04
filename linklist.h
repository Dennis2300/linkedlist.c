// linklist.h
#ifndef LINKLIST_H
#define LINKLIST_H

// Definition af struct for en node.
typedef struct Node {
    struct Node* nextNode;
    struct Node* prevNode;
    int data;
} Node;

// Definition af struct for en dobbelthægtet liste.
typedef struct LinkList {
    Node* head;
    Node* tail;
} LinkList;

// Funktioner til at arbejde med dobbelthægtet liste
LinkList* createLinkList();
Node* createNode(int data);
void appendNode(LinkList* list, int data);
void prependNode(LinkList* list, int data);
void deleteNode(LinkList* list, Node* node);
void printList(LinkList* list);
void freeList(LinkList* list);

#endif
