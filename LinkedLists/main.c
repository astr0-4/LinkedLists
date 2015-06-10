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
void removeNode(node *head, node *nodeToRemove);

int main(int argc, const char * argv[]) {
    node *current;
    node *head;

    node *myNode;
    myNode = (node *)malloc(sizeof(node));
    myNode->data = 15;
    myNode->next = NULL;
    
    head = NULL;
    // Task 1 - Create Linked List Function
    for(int i = 10; i > 0; i--) {
        current = (node *)malloc(sizeof(node));
        current->data = i;
        current->next = head;
        head = current;
    }

    
    search(head, myNode);
    insert(head, myNode);
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
    printf("node found %d", current->data);
    return current->next;
    }
    else {
        printf("node not found \n");
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
void removeNode(node *head, node *nodeToRemove) {
    node *current;
    node *previous;
    head = current;
    head = previous;
   
    while (current != NULL) {
        previous = current;
        current = current -> next;
        
        
    }
    
    
    
}
