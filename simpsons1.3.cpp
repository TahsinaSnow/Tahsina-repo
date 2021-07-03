#include<iostream>
#include<cmath>
using namespace std;
float f(float x)
{
    float ans;
    ans= pow(2.718,x);
    return ans;
}
int main()
{
    float a,b,x1,fa,fb,fx1,I,h;
    cin>>a>>b;
    fx1= f(x1);
    fa=f(a);
    fb=f(b);
    h=(b-a)/2;
    x1=a+h;
    I=(b-a)*(fa+4*fx1+fb)/6;
    cout<<I;
}
