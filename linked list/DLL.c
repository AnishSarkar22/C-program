#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <malloc.h>

typedef struct node {
    struct node* next;
    int data;
    struct node* prev;
} dl;

dl* head = NULL;

// Function prototypes
void create(dl*);
void display(dl*);
dl* insert_beg(dl*);
void insert_end(dl*);
void insert_before(dl*);
void insert_after(dl*);
void delete_beg(dl*);
void delete_end(dl*);
void delete_before(dl*);
void delete_after(dl*);
void delete_ap(dl*);

int main() {
    int option;
    system("cls"); // Use a more portable method for clearing the screen

    do {
        printf("\n\n**** MAIN MENU ****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete from any position");
        printf("\n 12: EXIT");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                head = (dl*)malloc(sizeof(dl));
                head->prev = NULL;  
                create(head);
                printf("\nDOUBLY LINKED LIST CREATED");
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insert_beg(head);
                break;
            case 4:
                insert_end(head);
                break;
            case 5:
                insert_before(head);
                break;
            case 6:
                insert_after(head);
                break;
            case 7:
                delete_beg(head);
                break;
            case 8:
                delete_end(head);
                break;
            case 9:
                delete_before(head);
                break;
            case 10:
                delete_after(head);
                break;
            case 11:
                delete_ap(head);
                break;
            case 12:
                exit(0); // Properly exit the program
            default:
                printf("Invalid option\n");
        }
    } while (option != 12);

    getch();
    return 0;
}

// Create the doubly linked list
void create(dl* ptr) {
    char ch;

    printf("Enter the element of the current node: ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;
    fflush(stdin);

    printf("\nDo you want to create more nodes (y/n): ");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        ptr->next = (dl*)malloc(sizeof(dl));
        ptr->next->prev = ptr;
        ptr = ptr->next;
        fflush(stdin);
        create(ptr);
    }
}

// Display the doubly linked list
void display(dl* ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Insert at the beginning of a doubly linked list
dl* insert_beg(dl* ptr) {
    dl* new_node;
    new_node = (dl*)malloc(sizeof(dl));

    printf("Enter the data part of the new node: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
    new_node->next = ptr;
    ptr->prev = new_node;

    return new_node;
}

// Insert at the end of a Doubly Linked List
void insert_end(dl* ptr) {
    dl* new_node;
    new_node = (dl*)malloc(sizeof(dl));

    printf("Enter the data part of the new node: ");
    scanf("%d", &new_node->data);

    while (ptr->next != NULL)
        ptr = ptr->next;

    new_node->prev = ptr;
    new_node->next = NULL;
    ptr->next = new_node;
}

// Insert before a node of a Doubly Linked List
void insert_before(dl* ptr) {
    dl* new_node;
    int ele;

    printf("Enter the element before which to insert: ");
    scanf("%d", &ele);

    while (ptr != NULL) {
        if (ptr->data == ele) {
            new_node = (dl*)malloc(sizeof(dl));

            printf("Enter the data part of the new node: ");
            scanf("%d", &new_node->data);

            new_node->prev = ptr->prev;
            new_node->next = ptr;
            ptr->prev->next = new_node;
            ptr->prev = new_node;
        }
        ptr = ptr->next;
    }
}

// Insert after a node of a Doubly Linked List
void insert_after(dl* ptr) {
    dl* new_node;
    int ele;

    printf("Enter the element after which to insert: ");
    scanf("%d", &ele);

    while (ptr != NULL) {
        if (ptr->data == ele) {
            new_node = (dl*)malloc(sizeof(dl));

            printf("Enter the data part of the new node: ");
            scanf("%d", &new_node->data);

            new_node->prev = ptr;
            new_node->next = ptr->next;
            ptr->next->prev = new_node;
            ptr->next = new_node;
        }
        ptr = ptr->next;
    }
}

// Delete from the beginning of a doubly linked list
void delete_beg(dl* ptr) {
    dl* ptr1;

    if (ptr == NULL)
        printf("The list is empty\n");
    else {
        ptr1 = ptr->next;
        ptr1->prev = NULL;
        head = ptr1;
        free(ptr);
    }
}

// Delete from the end of a doubly linked list
void delete_end(dl* ptr) {
    dl* ptr1;

    if (ptr == NULL)
        printf("The list is empty\n");
    else {
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr1 = ptr->prev;
        ptr1->next = NULL;
        free(ptr);
    }
}

// Delete a node after a given node from a doubly linked list
void delete_after(dl* ptr) {
    dl* ptr1;
    int val;

    if (ptr == NULL)
        printf("The list is empty\n");
    else {
        printf("Enter the value after which to delete: ");
        scanf("%d", &val);

        while (ptr != NULL) {
            if (ptr->data == val) {
                ptr1 = ptr->next;
                ptr->next = ptr1->next;
                if (ptr1->next != NULL) {
                    ptr1->next->prev = ptr;
                }
                free(ptr1);
            }
            ptr = ptr->next;
        }
    }
}

// Delete a node before a given node from a doubly linked list
void delete_before(dl* ptr) {
    dl* ptr1;
    int val;

    if (ptr == NULL)
        printf("The list is empty\n");
    else {
        printf("Enter the element before which to delete: ");
        scanf("%d", &val);

        while (ptr != NULL) {
            if (ptr->data == val && ptr->prev != NULL) {
                ptr1 = ptr->prev;
                ptr->prev = ptr1->prev;
                if (ptr1->prev != NULL) {
                    ptr1->prev->next = ptr;
                }
                free(ptr1);
            }
            ptr = ptr->next;
        }
    }
}

// Delete a node with a given value from a double linked list
void delete_ap(dl* ptr) {
    dl* ptr1;
    int val;

    if (ptr == NULL)
        printf("The list is empty\n");
    else {
        printf("Enter the value to be deleted: ");
        scanf("%d", &val);

        while (ptr != NULL) {
            if (ptr->data == val) {
                if (ptr->prev != NULL) {
                    ptr->prev->next = ptr->next;
                }
                if (ptr->next != NULL) {
                    ptr->next->prev = ptr->prev;
                }
                if (ptr == head) {
                    head = ptr->next;
                }
                free(ptr);
            }
            ptr = ptr->next;
        }
    }
}
