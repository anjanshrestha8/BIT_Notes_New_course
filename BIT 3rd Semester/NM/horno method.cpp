// LAB 1:
// 1. Title horner's method of finding polynomials at given value.
// 2. To find the value of a given polynomial of order 'n' at given value of x. eg: f(x)= x^3-4x^2+x+6 at x=2

/* theory:
        Algorithm:

        pn=qn
        p(n-1)=pn.x+a(n-1)
        p(n-2)=p(n-1).x+q(n-2)

        p0=p1+a0 */


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    int i=0,n=0,a[100],p,x=0;

    cout<<"enter the order(n): ";
    cin>>n;

    cout<<endl<<"Enter value of x: ";
    cin>>x;

    for(i=0;i<=(n);i++)
    {
        cout<<"Enter cofficient of "<<(i+1)<<" :";
        cin>>a[i];
    }
    p=a[n];
    for(i=(n-1);i>=0;i--)
    {
        p=(p*x)+a[i];
    }

    cout<<"Answer: "<<p<<endl;
    return 0;
}
