#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char url[100];  
    struct Node* prev;  
    struct Node* next;  
} Node;  


Node* head = NULL;  
Node* curr = NULL;  

void newPage(char* urls) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    strcpy(newNode->url, urls);
    newNode->next = NULL;  
    newNode->prev = curr;  
    
    if (head == NULL) 
    head = newNode;
    
    if (curr!= NULL) 
    curr->next = newNode;  
    curr = newNode;  
}


void goBack() {
    if (curr!= NULL && curr->prev!= NULL) {
        curr = curr->prev;  
        printf("moved back to: %s\n", curr->url);
    } else {
        printf("No previous page.\n");  
    }
}


void goForward() {
    if (curr!= NULL && curr->next!= NULL) {
        curr = curr->next;  
        printf("moved forward to: %s\n", curr->url);
    } else {
        printf("No forward page.\n");  
    }
}


void deletePage(int position) {
    if (head == NULL) {
        printf("History is empty.\n");
        return;

Node* temp = head;
for (int i = 1; temp!= NULL && i < position; i++) {
        temp = temp->next;
    }
    
if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;  
    }
    
 if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
 printf("Deleted: %s\n", temp->url);  
    free(temp);  
}}

void searchPage(char* Url) {
    Node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->url, Url) == 0) {
            printf("found %s", Url); 
            return ; 
    }
        temp = temp->next; 
    }
printf("Not found \n");;  
}

void displayHistory() {
    Node* temp = head;
    int i = 0;
    printf("Browser History:\n");

    while (temp != NULL) {
        i++;
        printf("%d. %s\n", i, temp->url);
        temp = temp->next;
    }
}


int main() {
    int choice, post;
    char url[50],Url[50];

    while (1) {
        
        printf("\nBrowser History Manager\n");
        printf("1. Add new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Delete specific history\n");
        printf("5. Display history\n");
        printf("6. Search history \n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  

       
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);  
                newPage(url);  
                printf("Visited: %s\n", url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                printf("Enter position to delete: \n");
                scanf("%d", &post);  
                deletePage(post);  
                break;
            case 5:
                displayHistory();
                break;
            case 6:
                printf("Enter url to search: \n");
                scanf("%s", &Url);  
                searchPage(Url); 
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}