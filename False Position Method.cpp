#include<iostream>
using namespace std;
float f(float x)
{
    float ans;
    ans=x*x-x-2;
    return ans;
}
int main()
{
    float x1,x2,x0,fx1,fx2;
    cin>>x1>>x2;
    while(x2-x1>0.001)
    {
        fx1=f(x1);
        fx2=f(x2);
        x0=x1-(fx1*(x2-x1))/(fx2-fx1);
        if(f(x0)==0)
        {
            cout<<"root="<<x0<<endl;
            break;
        }
        else if(f(x0)*f(x1)<0)
        {
            cout<<"root="<<x0<<endl;
            x2=x0;
        }
        else if(f(x0)*f(x2)<0)
        {
            cout<<"root="<<x2<<endl;
            x1=x0;
        }
    }
}
