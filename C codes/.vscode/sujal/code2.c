#include <stdio.h>
#include <math.h>
float f(float x);
int main ()
{
    float x0,x1,x2,q,err=1e-7;
    int R;
    printf("Enter the value of x0: \n");
    scanf("%f",&x0);
    printf("Enter the value of x1: \n");
    scanf("%f",&x1);
    while(fabs(x0-x1)>err)
    {
        x2=x1-((x1-x0)*(f(x1)/(f(x1)-f(x0))));
        x0=x1;
        x1=x2;
    }
    printf("The root of the given equation by second method is %7.5f(Correct upto 5D)",x0);
    return 0;
}

float f(float x)
{
    float y,z;
    int R=2;
    z=(R+1)/20;
    y=pow(x,x)+(z*log10((pow(x,2)+1)))-3.4 ;
    return y;
}

