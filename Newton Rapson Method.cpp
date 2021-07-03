#include<iostream>
#include<cmath>
using namespace std;
float f(float x)
{
    float ans;
    ans=x*x-3*x+2;
    return ans;
}
float dif(float x)
{
    float ans;
    ans=2*x-3;
    return ans;
}
int main()
{
    float x[20],fx1,fx2;
    int i=2;
    cin>>x[0];
    x[1]=x[0]-f(x[0])/dif(x[0]);
    cout<<x[1]<<endl;
    while(x[i-1]-x[i-2]>0.001)
    {
        x[i]=x[i-1]-f(x[i-1])/dif(x[i-1]);
        cout<<x[i]<<endl;
        i++;
    }
}
