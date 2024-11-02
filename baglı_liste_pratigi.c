#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct nodeFB {
    int id;
    int age;
    struct nodeFB *next;
};


struct nodeGS {
    int id;
    struct nodeGS *next;
};


struct newNodeFB {
    int id;
    int age;
    struct newNodeFB *next;
};


void insertFB(struct nodeFB **startFB, int id, int age) {
    struct nodeFB *newNode = (struct nodeFB *)malloc(sizeof(struct nodeFB));
    newNode->id = id;
    newNode->age = age;
    newNode->next = NULL;

    if (*startFB == NULL || (*startFB)->id > id) {
        newNode->next = *startFB;
        *startFB = newNode;
    } else {
        struct nodeFB *current = *startFB;
        while (current->next != NULL && current->next->id < id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void insertGS(struct nodeGS **startGS, int id) {
    struct nodeGS *newNode = (struct nodeGS *)malloc(sizeof(struct nodeGS));
    newNode->id = id;
    newNode->next = NULL;

    if (*startGS == NULL || (*startGS)->id < id) {
        newNode->next = *startGS;
        *startGS = newNode;
    } else {
        struct nodeGS *current = *startGS;
        while (current->next != NULL && current->next->id > id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printFB(struct nodeFB *startFB) {
    struct nodeFB *current = startFB;
    while (current != NULL) {
        printf(" %d %d\n", current->id, current->age);
        current = current->next;
    }
}


void printGS(struct nodeGS *startGS) {
    struct nodeGS *current = startGS;
    while (current != NULL) {
        printf(" %d\n", current->id);
        current = current->next;
    }
}


void createFinalList(struct newNodeFB **startNewFB, struct nodeFB *startFB, struct nodeGS *startGS) {
    struct nodeFB *currentFB = startFB;
    struct nodeGS *currentGS = startGS;
    struct newNodeFB *tail = NULL; 

    while (currentFB != NULL || currentGS != NULL) {
        if (currentFB != NULL) {
            struct newNodeFB *newNodeFB = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
            newNodeFB->id = currentFB->id;
            newNodeFB->age = currentFB->age;
            newNodeFB->next = NULL;

            if (*startNewFB == NULL) {
                *startNewFB = newNodeFB;
                tail = newNodeFB;
            } else {
                tail->next = newNodeFB;
                tail = newNodeFB;
            }

            currentFB = currentFB->next;
        }

        if (currentGS != NULL) {
            struct newNodeFB *newNodeGS = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
            newNodeGS->id = currentGS->id;
            newNodeGS->age = 0; 
            newNodeGS->next = NULL;

            if (*startNewFB == NULL) {
                *startNewFB = newNodeGS;
                tail = newNodeGS;
            } else {
                tail->next = newNodeGS;
                tail = newNodeGS;
            }

            currentGS = currentGS->next;
        }
    }
}


void printAll(struct newNodeFB *startNewFB) {
    struct newNodeFB *current = startNewFB;
    while (current != NULL) {
        if (current->age != 0) {
            printf(" %d %d\n", current->id, current->age);
        } else {
            printf(" %d\n", current->id);
        }
        current = current->next;
    }
}

struct nodeFB *startFB = NULL;
struct nodeGS *startGS = NULL;
struct newNodeFB *startNewFB = NULL;

int main()
{
    int id, age;
    scanf("%d", &id);
    while(id != -1) {
        scanf("%d", &age);
        insertFB(&startFB, id, age);
        scanf("%d", &id);
    }

    scanf("%d", &id);
    while(id != -1) {
        insertGS(&startGS, id);
        scanf("%d", &id);
    }

    printFB(startFB); 
    printGS(startGS); 

    createFinalList(&startNewFB, startFB, startGS); 

    printAll(startNewFB); 

    return 0;
}
