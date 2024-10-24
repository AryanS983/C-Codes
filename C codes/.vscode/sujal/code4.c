//Integration
#include <stdio.h>
#include <math.h>
float f(float x);
int main() {
    float a0,b,h,sum,a,pi;
    int n,i,k;
    pi=4*atan(1);
    a0=pi/18;
    b=5*pi/18;
    n=12;
    printf("enter the last digit of your roll no: \n");
    scanf("%d",&k);
    a0=(1+k)/20;
    h=b-a0/n;
    sum=0;
    for (i=0;i<=n-1;i++){
        sum=sum+(h/2)*(f(a0+i*h)+f(a0+(i+1)*h));
    }
    printf("The value of integral correct upto 4D is %6.4f",sum);
    return 0;
}

float f(float x){
    float y,a;
    y=1/pow(1+a*pow(sin(x),4),1.5);
    return y;
}