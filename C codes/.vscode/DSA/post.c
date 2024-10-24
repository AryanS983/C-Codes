#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
char stack[20];
int top=-1;
char ch;

void push(int val){
    stack[++top]=val;
}

int pop(){
    return stack[top--];
}

int main(){
    char input[20];
    char* e;
    e=input;
    printf("Enter postfix expression: ");
    scanf("%s", input);
    while(*e!='\0'){
        int n1,n2,n3;
        if (isdigit(*e)){
            n1=*e-'0';
            push(n1);
        }
        else{
            n1=pop();
            n2=pop();
            switch(*e){
                case '^':
                    n3=pow(n2,n1);break;
                case '*':
                    n3=n2*n1;break;
                case '/':
                    n3=n2/n1;break;
                case '+':
                    n3=n2+n1;break;
                case '-':
                    n3=n2-n1;break;
            }
            push(n3);
        }
        e++;
    }
    
    printf("Output: %d",pop());
    return 0;
}