//implement a queue using array

#include <stdio.h>
#include <stdlib.h>

#define size 100

static int front = -1;
static int rear = -1;
int a[size];

void create(int *);
void enqueue(int *, int);
void dequeue(int *);
void display(int *);

int main() {
    int data;
    int choice;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y') {
        system("cls");
        printf("\n Main Menu\n");
        printf("\n1. Create Queue using array");
        printf("\n2. View Queue");
        printf("\n3. Push elements into the Queue");
        printf("\n4. Pop elements from the Queue");
        printf("\n5. Exit\n");
        printf("\n Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Creation of Queue\n");
                create(a);
                break;
            case 2:
                printf("\n Display the Queue\n");
                display(a);
                break;
            case 3:
                printf("\n Push into the Queue\n");
                printf("Enter the element to push: ");
                scanf("%d", &data);
                enqueue(a, data);
                break;
            case 4:
                printf("\n Pop from the Queue\n");
                dequeue(a);
                break;
            case 5:
                exit(0);
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4/5)\n");
        }
 
        printf("Do you want to continue? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch); // a space before %c is required to consume the newline character
    }

    return 0;
}

void create(int *t) {
    int i;
    system("cls");
    printf("\n Enter the no. of elements to be inserted: ");
    scanf("%d", &rear);
    for (i = 0; i < rear; i++) {
        printf("\n Enter the %dth element: ", i + 1); 
        scanf("%d", t + i); 
    }
    front = 0; 
}

void enqueue(int *t, int d) {
    if (rear == (size - 1)) {
        printf("\n\tQueue overflow\n");
        return;
    } else {
        rear++;
        t[rear] = d;
    }
}

void dequeue(int *t) {
    if (front == -1 || front > rear) {
        printf("\n\tQueue underflow\n");
        return;
    } else {
        int element = t[front];
        t[front] = 0;
        front++;
        printf("Popped element: %d\n", element);
    }
}

void display(int *t) {
    int i;
    system("cls");
    printf("\n The elements in Queue are: \n");
    for (i = front; i <= rear; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}
