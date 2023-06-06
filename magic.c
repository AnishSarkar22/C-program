#include <stdio.h>  
#include <conio.h>  
  
int main ()  
{  
    // declare integer variables  
    int n, temp, rev = 0, digit, sum = 0;  
      
    printf (" Enter a Number: \n");  
    scanf (" %d", &n); // get the number  
      
    temp = n; // assign the number to temp variable  
      
    // use while loop to calculate the sum of digits  
    while ( temp > 0)  
    {  
        // extract digit one by one and store into the sum  
        sum = sum + temp % 10; /* use modulus symbol to get the remainder of each iteration by temp % 10 */  
        temp = temp / 10;  
    }  
      
    temp = sum; // assign the sum to temp variable  
    printf (" \n The sum of the digits = %d", temp);  
      
    // get the reverse sum of given digits  
    while ( temp > 0)  
    {  
        rev = rev * 10 + temp % 10;  
        temp = temp / 10;  
    }  
      
    printf (" \n The reverse of the digits = %d", rev);  
      
      
    printf (" \n The product of %d * %d = %d", sum, rev, rev * sum);  
    // use if else statement to check the magic number  
    if ( rev * sum == n)  
    {  
        printf (" \n %d is a Magic Number. ", n);  
    }  
    else  
    {  
        printf (" \n %d is not a Magic Number. ", n);  
    }  
    return 0;  
      
}  