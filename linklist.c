#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

LinkList* createLinkList() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    return newNode;
}

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