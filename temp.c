#include <stdio.h>
#include <stdlib.h>


struct node
{
    int val;
    struct node* next;
};

int main()
{

}

void push()
{
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Not able to push");
    }
    else
    {
        
    }
}