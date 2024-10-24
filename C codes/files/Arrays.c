#include <stdio.h>
#include <string.h>
// void dis(int a[],int n){
//     int i;
//     for (i=0;i<n;i++)
//         printf("%d ",a[i]);
//     printf("\n");
// }
// void inc(int a[],int n){
//     int i;
//     for (i=0;i<n;i++)
//         a[i]=a[i]+1;
// }
// int main() {
//     int arr[]={10,4,5,9,3,1};
//     dis(arr,5);
//     inc(arr,5);
//     dis(arr,6);
//     return 0;
// }
void func(char a[]){
    int i;
    for (i=0;i<4;i++){
        printf("%c ",a[i]);
    }
}
int main (){
    int i=0,j=0;
    char city[]="KOLKATA";
    char city1[]={'K','O','L','K','A','T','A','\0'};
    char city2[]="PATNA";
    int num[]={1,2,3,4,5,6};
    char city3[100];
    printf("%s,%d,%s\n",city,sizeof(city),city1);
    while (city[i]!='\0'){
        city3[j]=city[i];
        j++;
        i++;
    }
    i=0;
    while (city2[i]!='\0'){
        city3[j]=city2[i];
        j++;
        i++;
    }
    city3[j]='\0';
    printf("%s\n",city3);
    func(city);
    char * ptr = city;

    ptr=city;
    
    printf("%d \n", sizeof(num));
    printf("%s", city);
    char ct[100];
    
    scanf("%[^\n]s", ct);
    printf("%s ", ct);
    char state [25];
    char add[100];
    strcpy(state, " West Bengal");
    strcat(add,city1);
    strcat(add,state);
    printf("%s", add);
    puts(city);
    puts(ptr);

    

    
    return 0;
    

}

