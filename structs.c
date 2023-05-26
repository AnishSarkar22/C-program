#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main()
{
    struct Student s1, s2;
    s1.age = 22;
    s1.gpa = 3.2;
    strcpy(s1.name, "Anuj");
    strcpy(s1.major, "IT");

    s2.age = 21;
    s2.gpa = 3.4;
    strcpy(s2.name, "Akash");
    strcpy(s2.major, "Business");

    printf("%f\n", s1.gpa);
    printf("%s\n", s1.major);
    printf("%s\n\n", s1.name);

    printf("%f\n", s2.gpa);
    printf("%s\n", s2.major);
    printf("%s\n", s2.name);

    return 0;
}