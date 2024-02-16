//implement a queue using linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int x;
    struct queue *next;
} qu;

qu *head = NULL;

void create(qu *);
void insert(qu *);
void delete_q(qu *);
void display(qu *);

int main() {
    qu *ptr;
    int choice;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y') {
        system("cls");
        fflush(stdin);
        ptr = (qu *)malloc(sizeof(qu));
        head = ptr;

        printf("\n Main Menu\n");
        printf("1. Create Queue\n");
        printf("2. View Queue\n");
        printf("3. Insert elements into the Queue\n");
        printf("4. Delete elements from the Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCreation of Queue\n");
                create(head);
                break;
            case 2:
                printf("\nDisplay the Queue\n");
                display(head);
                break;
            case 3:
                printf("\nInsert into the Queue\n");
                insert(head);
                break;
            case 4:
                printf("\nDelete from the Queue\n");
                delete_q(head);
                break;
            case 5:
                exit(0);
            default:
                printf("\nPlease Enter a Valid Choice (1/2/3/4/5)\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);
    }

    return 0;
}

void create(qu *ptr) {
    char ch = 'y';
    printf("\nEnter the element of the current node: ");
    scanf("%d", &ptr->x);
    ptr->next = NULL;

    printf("Do you want to continue? (y/n): ");
    fflush(stdin);
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        ptr->next = (qu *)malloc(sizeof(qu));
        ptr = ptr->next;
        create(ptr);
    }
}

void display(qu *ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->x);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert(qu *ptr) {
    qu *new;
    new = (qu *)malloc(sizeof(qu));

    while (ptr->next != NULL)
        ptr = ptr->next;

    new->next = ptr->next;
    ptr->next = new;

    printf("Enter the element of the new node: ");
    scanf("%d", &new->x);
}

void delete_q(qu *ptr) {
    qu *loc;

    if (ptr == NULL) {
        printf("\nQueue Empty\n");
        return;
    } else {
        head = ptr->next;
        loc = ptr;
        free(loc);
    }
}
