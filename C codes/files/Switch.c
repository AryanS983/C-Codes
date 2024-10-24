#include <stdio.h>
int main () {
    int day;
    scanf("%d",&day);
    switch(day){
        case 1: printf("Mon"); break;
        case 2: printf("Tue"); break;
        case 3: printf("Wed"); break;
        case 4: printf("Thu"); break;
        case 5: printf("Fri"); break;
        default: printf("lol");
    }
    return 0;
}
// #include <stdio.h>
// int main () {
//     char day;
//     scanf("%s",&day);
//     switch(day){
//         case 'o': printf("Mon"); break;
//         case 'p': printf("Tue"); break;
//         case 'q': printf("Wed"); break;
//         case 'r': printf("Thu"); break;
//         case 's': printf("Fri"); break;
//         default: printf("lol");
//     }
//     return 0;
// }