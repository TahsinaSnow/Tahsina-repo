#include<iostream>
using namespace std;
float f(float x)
{
    return x*x*x+1;
}
int main()
{
    float a,b,ans;
    cin>>a>>b;
    float fa= f(a);
    float fb= f(b);
    ans = (b-a)*(fa+fb)/2;
    cout<<ans;
}
