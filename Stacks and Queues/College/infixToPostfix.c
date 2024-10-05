#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
char s[MAX];
int top=-1;
void push(char item){
    if(top<MAX-1){
    s[++top]=item;
    return;}
    printf("Stack full");
    return;
}
char pop(){
    if(top>=0)
    return s[top--];
    return '\0';
}
int isOperator(char x){
    if(x=='^'||x=='*'||x=='/'||x=='+'||x=='-')
    return 1;
    return 0;
}
int prec(char x){
    if(x=='^')
    return 3;
    else if(x=='*' || x=='/')
    return 2;
    else if(x=='+' || x=='-')
    return 1;
    else
    return 0;
}
void infixToPostfix(char *infix, char *postfix){
    int i,k=0;
    char c;
    int n=strlen(infix);
    for(i=0;i<n;i++){
        if(isalnum(infix[i])){
            postfix[k++]=infix[i];
        }
        if(infix[i]=='('){
            push(infix[i]);
        }
        if(infix[i]==')'){
            while(infix[i]!='(' && top!=-1){
                postfix[k++]=pop();
            }
            pop();
        }
        if(isOperator(infix[i])){
            while(top!=-1 && prec(s[top])>=prec(infix[i])){
                postfix[k++]=pop();
            }
            push(infix[i]);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
