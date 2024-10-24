#include <stdio.h>
// int top=-1;
// void pt(){
//     printf("%d",top);
// }
// int main (){
//     top=top+1;
//     pt();
//     return 0;
// }
int main() {
    char input[20]="lodalahsun";
    char* ptr;
    ptr=input;
    printf("%c", *ptr);
    ptr++;
    printf("%c", *ptr);

    return 0;
}