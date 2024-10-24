//Range Kutta Method
#include <stdio.h>
#include <math.h>
float f(float x,float y,float p);
int main() {
    float x0,y0,xn,n,k,k1,k2,k3,k4,p;
    int R;
    printf("Enter the last digit of your roll no:\n");
    scanf("%d",&R);
    x0=0;
    y0=1.1+(R/50);
    xn=1.0;
    n=0.1;
    p=(28+R)/20.;
    printf("y(%3.1f) = %6.4f\n",x0,y0);
    while(x0<xn){
        k1=n*f(x0,y0,p);
        k2=n*f(x0+n/2.,y0+k1/2.,p);
        k3=n*f(x0+n/2.,y0+k2/2.,p);
        k4=n*f(x0+n,y0+k3,p);
        k=(1./6.)*(k1+2.*k2+2.*k3+k4);
        y0+=k;
        x0+=n;
        printf("y(%3.1f) = %6.4f\n",x0,y0);
    }
    printf("CORRECT UPTO 4D \n");
    return 0;
}

float f(float x,float y, float p){
    float z;
    z=sqrt((p+x*pow(y,2)+(p-1)*pow(x,2)*y)/(2.+1.3*pow(x,2)+3.1*pow(y,2)));
    return z;
}