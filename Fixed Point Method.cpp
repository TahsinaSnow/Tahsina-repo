#include<iostream>
using namespace std;
float g(float x)
{
    float f;
    f=(5+x*x)/(2*x);
    return f;
}
int main()
{
    float x0,x1,root,i;
    cin>>x0;
    while (g (x1-x0)>=0.001)
    {
        root=g(x0);
        cout<<root<<endl;
        x1=x0;
        x0=root;
        i++;
    }
}
