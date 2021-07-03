#include<iostream>
#include<cmath>
using namespace std;
float func(float x)
{
    float f;
    f=x*x-4*x-10;
    return f;
}
int main()
{
    float x1,x2;
    float x3,a,b,root,i;
    cin>>x1>>x2;
    while(abs(x2-x1)>=0.001)
    {
        a=func(x1);
        b=func(x2);
        x3=x2-(b*(x2-x1))/(b-a);

        cout<<x3<<endl;
        x1=x2;
        x2=x3;
        i++;
    }
}
