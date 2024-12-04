#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// Allocates memory for a new LinkList and initializes its head and tail to NULL.
LinkList* createLinkList() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Allocates memory for a new Node, sets its data, and initializes its next and previous pointers to NULL.
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    return newNode;
}

// appendNode(LinkList* list, int data): Creates a new node and appends it to the end of the list. If the list is empty, the new node becomes both the head and tail.
void appendNode(LinkList* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) { // Hvis listen er tom
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->nextNode = newNode;
        newNode->prevNode = list->tail;
        list->tail = newNode;
    }
}

// reates a new node and prepends it to the beginning of the list. If the list is empty, the new node becomes both the head and tail.
void prependNode(LinkList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) { // Hvis listen er tom
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->nextNode = list->head;
        list->head->prevNode = newNode;
        list->head = newNode;
    }
}

// deleteNode(LinkList* list, Node* node): Removes the specified node from the list and frees its memory. Updates the head or tail pointers if necessary.
void deleteNode(LinkList* list, Node* node) {
    if (node == NULL) return;
    if (node->prevNode) {
        node->prevNode->nextNode = node->nextNode;
    } else { // Sletning af head
        list->head = node->nextNode;
    }
    if (node->nextNode) {
        node->nextNode->prevNode = node->prevNode;
    } else { // Sletning af tail
        list->tail = node->prevNode;
    }
    free(node);
}

// Iterates through the list and prints the data of each node.
void printList(LinkList* list) {
    Node* current = list->head;
    while (current) {
        printf("%d", current->data);
        if (current->nextNode) {
            printf(" ");
        }
        current = current->nextNode;
    }
}

// Iterates through the list, frees each node, and finally frees the list itself.
void freeList(LinkList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->nextNode;
        free(current);
        current = next;
    }
    free(list);
}