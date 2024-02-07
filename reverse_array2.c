#include<stdio.h>
#include<stdlib.h>

//reverse the array

void input(int *);
void display(int *);
void rev(int *, int *);

int n, *p,*q;

int main()
{

    printf("Enter no of terms in the array - ");
    scanf("%d",&n);
    p = (int*)malloc(n*sizeof(int));
    q = (int*)malloc(n*sizeof(int));
    input(p);

    printf("The input array is \n");

    display(p);

    printf("\nReversing the array......\n");

    rev(p,q);

    printf("The Reversed array is - \n");

    display(q);

    return 0;

}

void input(int *ptr)
{
    int i;
    for(i = 0; i<n; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }
}

void display(int *ptr)
{
    int i;
    for(i = 0; i<n; i++)
    {

        printf("%d\t",*(ptr));
        ptr++;
    }

}

void rev(int *ptr1,int *ptr2)
{
    int i;
    for(i = 0; i<n; i++)
    {
        *ptr1++;

    }
    *ptr1--;

    for(i = 0; i<n; i++)
    {
        *(ptr2) = *(ptr1);
        *ptr1--;
        *ptr2++;
    }
}








