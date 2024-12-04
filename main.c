#include <stdio.h>
#include "linklist.h"

int main() {
    LinkList* list = createLinkList();
    printf("Created a new linked list.\n");

    appendNode(list, 10);
    printf("Appended 10 to the list.\n");
    printf("--------------------\n");
    appendNode(list, 20);
    printf("Appended 20 to the list.\n");
    printf("--------------------\n");
    prependNode(list, 5);
    printf("Prepended 5 to the list.\n");
    printf("--------------------\n");

    printf("Current list: ");
    printList(list);
    printf("\n");
    printf("--------------------\n");

    deleteNode(list, list->head->nextNode);
    printf("Deleted the second node (10) from the list.\n");
    printf("--------------------\n");

    printf("Current list: ");
    printList(list);
    printf("\n");
    printf("--------------------\n");

    freeList(list);
    printf("Freed the list.\n");

    return 0;
}


//To start the program, run the command:
// gcc -o run-linklist main.c linklist.c
//./run-linklist