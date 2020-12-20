#include<math.h>
void lsm(long int n,double x[n],double y[n],double bar[3])
{
    double b1,b2,r1,x_,y_;
    long int i;
    for (i=0;i<n;i++)
    {
        x_+=x[i];y_+=y[i];
    }
    x_=x_/n;y_=y_/n; // mean values of x and y
    for (i=0;i<n;i++)
    {
        b1+=(x[i]-x_)*(y[i]-y_);b2+=pow(x[i]-x_,2);
        r1+=pow(y[i]-y_,2);
    }
    r1=sqrt(b2*r1);
    bar[0]=b1/b2;        // b
    bar[1]=y_-bar[0]*x_; // a
    bar[2]=b1/r1;        // r
}
