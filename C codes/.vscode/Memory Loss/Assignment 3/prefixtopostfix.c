#include <stdio.h>
#include <string.h>
#include<math.h>
#include <stdlib.h>
#define max 50

char stack[max][max];
int top=-1;
void push(char *str);
char * pop();
void prefixtopostfix(char prefix[]);


void push(char *str)
{
        if(top > max)
        {
                printf("\nStack overflow\n");
                exit(1);
        }
        else
        {
                top=top+1;
                strcpy( stack[top], str); 
        }
}

char *pop(){
    if(top==-1){
        printf("Underflow Lund lele mera");
        exit(1);
    }
    else{
        return stack[top--];
    }
}

void prefixtopostfix(char prefix[]){
    char symbol;
    char temp[2];
    char opp1[max],opp2[max];
    char strin[max];
    int i;
    for(i=strlen(prefix)-1;i>=0;i--){
        symbol=prefix[i];
        temp[0]=symbol;
        temp[1]='\0';
        switch (symbol){
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                strcpy(opp1,pop());
                strcpy(opp2,pop());
                strcpy(strin,opp1);
                strcat(strin,opp2);
                strcat(strin,temp);
                push(strin);
                break;
            default:
                push(temp);
        }
    }
    printf("Postfix expression: ");
    puts(stack[0]);
}

int main(){
    char prefix[max];
    printf("Randi ka ladka code: Prefix Expression Dal Gandu: ");
    gets(prefix);
    prefixtopostfix(prefix);
    return 0;
}