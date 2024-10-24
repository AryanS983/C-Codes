#include <stdio.h>
#include <math.h>
float f1(float x);
float f2(float x);
float f3(float x);
int main () {
    float a,x,y0,y1;
    int R;
    printf("Enter the last digit of your roll no:\n");
    scanf("%d",&R);
    a=0;
    y0=0.+(R/10);
    x=0.4;
    printf("The first approximation is:\n");
    y1=y0+f1(x);
    printf("y(%3.1f)=%7.5f\n",x,y1);
    printf("The second approximation is:\n");
    y1=y0+f2(x);
    printf("y(%3.1f)=%7.5f\n",x,y1);
    printf("THe third approximation is:\n");
    y1=y0+f3(x);
    printf("y(%3.1f)=%7.5f\n",x,y1);
    printf("correct upto 5D\n");
    return 0;
}

float f1(float x){
    float y;
    y=pow(x,3)/3;
    return y;
}

float f2(float x){
    float y;
    y=(pow(x,3)/3)+(pow(x,7)/63);
    return y;
}
float f3(float x){
    float y;
    y=pow(x,3)/3+pow(x,7)/63+2*pow(x,11)/2079+pow(x,15)/59535;
    return y;
}