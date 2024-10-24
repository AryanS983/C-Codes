//Newton Raphson Method
#include <stdio.h>
#include <math.h>
float f(float x);
float f1(float x);
int main (){
    float x, h, q, pnr=1e-7 ;
    int R;
    printf("Enter the initial value of the interval\n");
    scanf("%f",&x);
    if (fabs(f1(x))<0.00001){
        printf("Change the initial value");
    }
    else{
        h=f(x)/f1(x);
        while (fabs(h)>pnr){
            x=x+h;
            h=-f(x)/f1(x);
        }
        printf("The root of the given equation by Newton Raphson method is %7.5f",x);
    }
    return 0;
}

float f(float x){
    float y,z;
    int R=2;
    z=(R/10);
    y=exp(x*tan(x))+pow(x,2)*log(x+1)-9.2+z;
    return y;
}

float f1 (float x){
    float y,z;
    int R=2;
    z=(R/10);
    y=exp(x*tan(x))+(tan(x)+(x*pow((1/cos(x)),2)))+(pow(x,2)/(1+x))+2*x*(log(x+1));
    return y;
}