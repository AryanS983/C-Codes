#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * mergeAlternately(char * word1, char * word2){
    int n,m,i=0,j=0,k=0;
    m=strlen(word1);
    n=strlen(word2);
    char* word3= (char*)malloc((n+m+1)*sizeof(char));
    while(i<m||j<n){
        if(i<m){
            word3[k]=word1[i];
            i++;
            k++;
        }
        if(j<n){
            word3[k]=word2[j];
            j++;
            k++;
        }
    }
    word3[k]='\0';
    return word3;
}
int main() {
    char a[]= "bhosdi";
    char b[]="ke";
    char* c;
    c=mergeAlternately(a,b);
    printf("%s",c);
    return 0;
}