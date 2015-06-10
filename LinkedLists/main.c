//
//  main.c
//  LinkedLists
//
//  Created by Alex on 2015-06-10.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

void listAll();
node * search(node *head, node *nodeToFind);
void insert(node *head, node *nodeToAdd);
void removeNode(node **head, int dataForRemoval);
node initializeNode(node *head);
void deallocateNode(node *head);

int main(int argc, const char * argv[]) {
    node *current;
    node *head;

    node *myNode;
    myNode = (node *)malloc(sizeof(node));
    myNode->data = 11;
    myNode->next = NULL;
    
    node *myOtherNode;
    myOtherNode = (node *)malloc(sizeof(node));
    myOtherNode->data = 8;
    myOtherNode->next = NULL;
    //head = NULL;
    
 //    Task 1 - Create Linked List Function
    
    for(int i = 10; i > 0; i--) {
        current = (node *)malloc(sizeof(node));
        current->data = i;
        current->next = head;
        head = current;
    }

    search(head, myNode);
    insert(head, myNode);
    removeNode(&head, 11);
    listAll(head);
    deallocateNode(head);
    listAll(head);
    return 0;
}

// Task 2 - List All Function
void listAll(node *head) {
    node *current;
    current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

//Task 3 - Search Function
node * search(node *head, node *nodeToFind) {
    node *current;
    current = head;
    
    while ((current->data != nodeToFind->data) && current->next != NULL) {
        current = current->next;
    }
    if(current->data == nodeToFind->data) {
    printf("node found %d\n", current->data);
    return current->next;
    }
    else {
        printf("node not found\n");
        return NULL;
    }
}

//Task 4 - Insert Function
void insert(node *head, node *nodeToAdd) {
    node *current;
    current = head;
    
    while (current->next != NULL) {
        current = current -> next;
    }
    
    current->next = nodeToAdd;
    nodeToAdd->next = NULL;
    printf("Node added %d \n", nodeToAdd->data);
    printf("Node to add pointer: %p \n", nodeToAdd);
    printf("Current Node's pointer: %p \n", current->next);
}

//Task 5 Removal Function
void removeNode(node **head, int dataForRemoval) {
    node *current;
    node *previous = NULL;
    current = *head;
    
    while (current != NULL && dataForRemoval != current->data) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) { //element not found
        printf("Node not found. No removal done. \n");
    }
    if (current == *head) { //delete first node
        *head = (*head)->next;
    }
    
    else {
        previous->next = current->next;
        printf("Node removed: %d\n", current->data);
        free(current);
    }
}

//Task 6 Initialization Function
//node initializeNode(node *head) {
//    node *current;
//    head = (node *)malloc(sizeof(node));
//    return *head;
//}
// maybe initialize using the insert function?

//Task 7 Deallocation
void deallocateNode(node *head) {
    node *current;
    while ((current = head) != NULL) {
        head = head->next;
        printf("freeing: %d\n", current->data);
        free(current);
        
    }
}

