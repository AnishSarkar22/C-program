// array of 10 numbers and reverse their numbers
#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr1 = arr; // pointer to the start of the array
    int *ptr2 = &arr[9]; // pointer to the end of the array

    while (ptr1 < ptr2) {
        // swap the values pointed to by ptr1 and ptr2
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;

        // move the pointers towards the center of the array
        ptr1++;
        ptr2--;
    }

    // print the reversed array
    printf("Reversed array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
