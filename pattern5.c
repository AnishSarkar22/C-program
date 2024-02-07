#include <stdio.h>

void printpattern(int n){
    int i, j;
    for (i=1; i <= n; i++){
        for (j=1; j<=i; j++){
            printf("%d", i);
        }
        printf("\n");
    }
    for (i=n-1;i>0; i--){
        for (j=i; j>0; j--){
            printf("%d",i);
        }
        printf("\n");
    }
}

int main(){
    int n =4;
    printpattern(n);

    return 0;
}