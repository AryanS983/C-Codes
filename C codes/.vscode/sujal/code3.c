//Bisection Method
#include <stdio.h>
#include <math.h>
float f(float x);
int main () {
    float a,b,x,error= 1e-6;
    printf("Enter the end points of the Interval: \n");
    scanf("%f%f",&a,&b);
    if (f(a)*f(b)>0){
        printf("Change the initial intervals\n");
    }
    else {
        while (fabs(b-a)>error && f(a)!=0 && f(b)!=0){
            x=(a+b)/2;
            if (f(a)*f(x)<0){
                b=x;
            }
            else {
                a=x;
            }
        }
        if (f(a)==0){
            printf("The root is %8.5f (correct up to five decimal places)",a);
        }
        else if (f(b)==0){
            printf("The root is %8.5f (correct up to five decimal places)",b);
        }
        else {
        printf("The root is %8.5f (correct up to five decimal places)",x);
        }
       
    }
    return 0;
}

float f (float x ){
    float y;
    y=exp(pow(x,2))+log(pow(x,2)+2)- 2.5*(x+1);
    return y;
}