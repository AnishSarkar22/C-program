#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create(struct node *);
void display(struct node *);
void insert_beg();
void insert_af(struct node *, int);
void insert_bef(struct node *, int);
void insert_bet(struct node *, int, int);
void insert_end(struct node *);
void del_anypos(struct node *, int);
struct node *reverse(struct node *);
void sort(struct node *);
void swap(struct node *, struct node *);
void search(struct node *, int);

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    int no, ele, ele1, ele2;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        system("cls");
        printf("-----------MAIN MENU-----------");
        printf("\n 1) Create a List");
        printf("\n 2) To insert a new number at the beginning\n");
        printf("\n 3) To insert a new number after the number\n");
        printf("\n 4) To insert a new number before the number\n");
        printf("\n 5) To insert a new number between the two numbers\n");
        printf("\n 6) To search a number in the list\n");
        printf("\n 7) To sort the list\n");
        printf("\n 8) To delete a number in the list\n");
        printf("\n 9) To reverse the list\n");
        printf("\n 10) To display the list\n");
        printf("\n 11) For EXIT\n");
        printf("\nEnter your Choice:");
        scanf("%d", &no);
        switch (no)
        {
        case 1:
            printf("\nCreating a list:\n");
            create(head);
            break;
        case 2:
            printf("\nInsert new number at the beginning:\n");
            insert_beg();
            break;
        case 3:
            printf("\nEnter the number after which you want to insert:");
            scanf("%d", &ele);
            printf("\nInsert new number after the number:\n");
            insert_af(head, ele);
            break;
        case 4:
            printf("\nEnter the number before which you want to insert:");
            scanf("%d", &ele);
            printf("\nInsert new number before the number:\n");
            insert_bef(head, ele);
            break;
        case 5:
            printf("\nEnter the numbers between which you want to insert:");
            scanf("%d%d", &ele1, &ele2);
            printf("\nInsert new number between the two numbers:\n");
            insert_bet(head, ele1, ele2);
            break;
        case 6:
            printf("\nEnter the number you want to search:");
            scanf("%d", &ele);
            printf("\nSearch number in a list\n");
            search(head, ele);
            break;
        case 7:
            printf("\nList has been sorted successfully\n");
            sort(head);
            break;
        case 8:
            printf("\nDelete a number");
            printf("\nEnter the number you want to delete from the list:\n");
            scanf("%d", &ele);
            del_anypos(head, ele);
            break;
        case 9:
            head = reverse(head);
            printf("\nList has been reversed successfully\n");
            break;
        case 10:
            printf("\nLinked List:\n");
            display(head);
            break;
        default:
            printf("\nYour choice is WRONG\n");
            exit(0);
        }
        printf("\nDo you want to CONTINUE?:");
        scanf(" %c", &ch);
    }
    return 0;
}

void create(struct node *newnode)
{
    char ch;
    printf("Enter the data to be entered:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    printf("Do you want to enter another element:");
    scanf(" %c", &ch);
    if ((ch == 'y') || (ch == 'Y'))
    {
        newnode->next = (struct node *)malloc(sizeof(struct node));
        newnode = newnode->next;
        create(newnode);
    }
}

void display(struct node *newnode)
{
    while (newnode != NULL)
    {
        printf("%d->", newnode->data);
        newnode = newnode->next;
    }
    printf("NULL");
}

void insert_beg()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be entered:");
    scanf("%d", &new->data);
    new->next = head;
    head = new;
}

void insert_af(struct node *newnode, int n)
{
    int flag = 0;
    while (newnode != NULL)
    {
        if (newnode->data == n)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            printf("Enter the element to be entered:");
            scanf("%d", &new->data);
            new->next = newnode->next;
            newnode->next = new;
            flag = 1;
        }
        newnode = newnode->next;
    }
    if (flag == 0)
    {
        printf("Element not found");
    }
}

void insert_bef(struct node *newnode, int n)
{
    int flag = 0;
    struct node *newnode1 = newnode->next;
    while (newnode1 != NULL)
    {
        if (newnode1->data == n)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->next = newnode1;
            newnode->next = new;
            printf("Enter the element to be entered:");
            scanf("%d", &new->data);
            flag = 1;
        }
        newnode = newnode->next;
        newnode1 = newnode1->next;
    }
    if (flag == 0)
    {
        printf("Element not found");
    }
}

void insert_bet(struct node *newnode, int n1, int n2)
{
    int flag = 0;
    struct node *newnode1 = newnode->next;
    while (newnode1 != NULL)
    {
        if (newnode1->data == n2 && newnode->data == n1)
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->next = newnode1;
            newnode->next = new;
            printf("Enter the element to be entered:");
            scanf("%d", &new->data);
            flag = 1;
        }
        newnode = newnode->next;
        newnode1 = newnode1->next;
    }
    if (flag == 0)
    {
        printf("Element not found");
    }
}

void insert_end(struct node *newnode)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    while (newnode->next != NULL)
    {
        newnode = newnode->next;
    }
    printf("Enter the element to be entered:");
    scanf("%d", &new->data);
    new->next = NULL;
    newnode->next = new;
}

void del_anypos(struct node *newnode, int n)
{
    struct node *temp = newnode;
    struct node *prev = NULL;
    while (temp != NULL && temp->data != n)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Element not found");
        return;
    }
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
}

struct node *reverse(struct node *newnode)
{
    struct node *current1 = newnode;
    struct node *previous = NULL;
    while (current1)
    {
        struct node *counter = current1->next;
        current1->next = previous;
        previous = current1;
        current1 = counter;
    }
    newnode = previous;
    return newnode;
}

void sort(struct node *newnode)
{
    if (newnode == NULL)
    {
        return;
    }
    else
    {
        struct node *ptr = newnode;
        while (ptr)
        {
            struct node *ptr1 = ptr->next;
            while (ptr1)
            {
                if (ptr->data > ptr1->data)
                {
                    swap(ptr, ptr1);
                }
                ptr1 = ptr1->next;
            }
            ptr = ptr->next;
        }
    }
}

void swap(struct node *newnode, struct node *newnode1)
{
    int temp = newnode->data;
    newnode->data = newnode1->data;
    newnode1->data = temp;
}

void search(struct node *newnode, int ele)
{
    int flag = 0;
    int count = 1;
    while (newnode)
    {
        if (newnode->data == ele)
        {
            printf("Element found at position %d\n", count);
            flag = 1;
        }
        count += 1;
        newnode = newnode->next;
    }
    if (flag == 0)
    {
        printf("Element not found");
    }
}
