#include <stdio.h>
#include <stdlib.h>

int size = 5;
int arr[5];
int front = -1, rear = -1;
void enqueue(int val)
{
    if (((rear + 1) % size) == front)
    {
        printf("queue overflow\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = val;
    }
    else
    {
        rear = (rear + 1) % size;
        arr[rear] = val;
    }
}
int dequeue()
{
    int a = arr[front];
    if (front == -1)
    {
        return -1;
    }
    else if (front == rear)
    {
        front = rear = -1;
        return a;
    }
    else
    {
        front = (front + 1) % size;
        return a;
    }
}
int peek()
{
    if (front == -1)
    {
        return -1;
    }
    else
    {
        return arr[rear];
    }
}
void display()
{
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("elements of queue is %d\n", arr[i]);
        }
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            printf("elements of queue is %d\n", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("elements of queue is %d\n", arr[i]);
        }
    }
}

int main()
{
    int opt, val, a;
    do
    {
        printf("1.Do enqueue operation\n2.Do dequeue operation\n3.Do peek operation\n4.Display all the values\n5.Exit\n");
        printf("enter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("enter value to enque: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            a = dequeue();
            if (a == -1)
            {
                printf("queue is empty\n");
            }
            else
            {
                printf("dequeued element is %d\n", a);
            }
            break;
        case 3:
            a = peek();
            if (a == -1)
            {
                printf("queue is empty\n");
            }
            else
            {
                printf("peeked value is %d\n", a);
            }
            break;
        case 4:
            printf("displaying all the value of queue\n");
            display();
            break;
        case 5:
            printf("...The End...\n");
        }
    } while (opt < 5);
}