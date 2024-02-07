// Shunting Yard algorithm

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top=-1;

void push(char);
char pop();
int priority(char);

int main(){
    
    
    char p[100],x;
    printf("Enter the equation:");
    scanf("%s",p);
    char *q = p;
    push('(');

    while(*(q)!='\0'){
        if(isalnum(*(q))){
            printf("%c",*(q));
        }
        else if(*(q) == '('){
            push(*(q));
        }
        else if(*(q) == ')'){
            while((x = pop())!='('){
                printf("%c",x);
            }
        }
        else{
            if(priority(*(q)) <= priority(stack[top])){
                if(stack[top]=='('){
                    pop();
                }
                printf("%c",pop());
            }
            push(*(q));
        }
        q++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
    
    return 0;
}

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if(top == -1){
        return -1;
    }
    else{
        return (stack[top--]);
    }
}

int priority(char ch){
    if (ch =='('){
        return 0;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '^'){
        return 3;
    }
}