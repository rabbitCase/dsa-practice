/* Algorithm to convert an infix expression to postfix:
1) Scan through the infix expression from left to right
2) If an operand is encountered, push it into the postfix expression string
3) If an operator is encountered, push it into the stack only if the precedence value of this operator is greater than the operator currently at the top of the stack.
4) If the operator's precedence is not greater than the precedence of the element at the stack's top, then pop the elements (operators) of the stack until the precedence of the encountered element is greater than that of the operator at the top of the stack. All popped operators are simultaneously appended to the postfix expression as well.
5) If an opening bracket '(' is encountered, we push it into the stack.
6) If a closing bracket ')' is encountered, pop the elements of the stack until '(' is encountered and append the poppped elements into the postfix expression. Then pop one more time to remove the '(' as we dont need it.
7) Finally pop all the remaining elements in the stack and append them to the postfix expression. Also add a null character '\0' at the end of the expression as it is a character array.
*/
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
int prec(char x){//precedence follows BEDMAS rule
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
            pop();//pop the extra '('
        }
        if(isOperator(infix[i])){
            while(top!=-1 && prec(s[top])>=prec(infix[i])){
                postfix[k++]=pop();
            }
            push(infix[i]);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();//pop all remaining elements in the stack
    }
    postfix[k]='\0';//append null character at the end
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
