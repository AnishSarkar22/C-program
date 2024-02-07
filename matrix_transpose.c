#include <stdio.h>
#include <stdlib.h>

void input(int *);
void display(int *);
void transpose(int *, int *);
int i,j,n,r,c,*p,*q;
int main()
{
    printf("Enter no of rows and columns;\n ");
    scanf("%d %d", &r,&c);
    p = (int*)malloc(r*c*sizeof(int));
    q = (int*)malloc(r*c*sizeof(int));

    printf("Enter no of elements row wise for matrix 1 = \n");

    input(p);

    printf("1st matrix is - \n");

    display(p);
    printf("\n");

    printf("\nTranspose of the matrix is :\n");
    transpose(p,q);

    display(q);
    exit(0);
}

void input(int *ptr)
{
    for(i = 0; i<r; i++)
    {
        for(j = 0; j<c; j++)
        {
            scanf("%d", (ptr+i*r+j));
        }
    }
}


void display(int *ptr)
{
    for(i = 0; i<r; i++)
    {
        for(j = 0; j<c; j++)
        {
            printf("%d\t",*(ptr+i*r+j));
        }
        printf("\n");
    }
}

void transpose(int *ptr1, int *ptr2)
{
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)
                *(ptr2+i*c+j) = *(ptr1+j*r+i);
        }
}
