//Pointer is a type of data that is a memory address

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int age =30;
    int *pAge = &age;    //creating a pointer for age
    double gpa =3.4;
    double *pGpa = &gpa;    //creating a pointer for gpa
    char grade ='A';
    char *pGrade = &grade;    //creating a pointer for grade 

    printf("age: %p\ngpa: %p\ngrade: %p\n\n", &age, &gpa, &grade);       //output of memory addresses
    printf("age: %p\ngpa: %p\ngrade: %p\n\n", pAge, pGpa, pGrade);       //output of memory addresses with pointers    

    printf("age: %d\n", *pAge);   //dereferencing the 'Age' pointer 
    printf("age: %d", *&age);   //also dereferencing the 'Age' pointer 


    return 0;   
}


/* Deferencing a pointer means to grab the actual value stored at the memory address of that pointer.
    We use "*" to dereference a pointer.  */