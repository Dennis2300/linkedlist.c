#include <stdio.h>
#include "linklist.h"

int main() {
    LinkList* list = createLinkList();

    appendNode(list, 10);
    appendNode(list, 20);
    prependNode(list, 5);
    printList(list); // Output: 5 10 20

    deleteNode(list, list->head->nextNode);
    printList(list); // Output: 5 20

    freeList(list);
    return 0;
}

//To start the program, run the command:
// gcc -o run-linklist main.c linklist.c
//./run-linklist