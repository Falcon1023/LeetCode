#include<iostream>
#include<cmath>
#define esp 1e-4
using namespace std;
int main()
{
    double l,c,n;
    double left,right,mid;
    double r;
    double s;
    while(scanf("%lf%lf%lf",&l,&n,&c)==3)
    {
        if(l==-1&&c==-1&&n==-1)
            break;
        left=0;
        right=l/2;  
        s=(1+n*c)*l;
        while(right-left>esp)
        {
            mid=(left+right)/2;
            r=(mid*mid+l*l/4)/(2*mid);
            if(r*asin(l/(2*r))<s/2)
                left=mid;
            else
                right=mid;
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}
