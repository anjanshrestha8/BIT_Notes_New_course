/* LAB 3: Newton Raphson Method

Objective: To find the root of the equation to required degree of accuracy

Theory:

    Algorithm:

            1. Assign initial value of x0 & read EPS
            2. Evaluate fx0 & f'x0
            3. if fx0=0, xo = root
            4. find x1x0-fx0/f'x0
            5. check for accuracy: |(x1-x0)x1| < EPS
            6. x0=x1 & repeat 3,4,5
            7. print x1
            8. stop
Problem:
    Given fx=x^2-3x+2 and EPS = 0.000001 */

#include <iostream>
#include <math.h>
#include <stdlib.h>

#define eps 0.000001
#define f(x) (x*x)-(3*x)+2
#define f1(x) (2*x)-3

using namespace std;

int main()
 {
     double x0,res1,res2,x1,data;

     cout<< "Enter initial values: ";
     cin>>x0;
lit:
     res1= f(x0);
     res2= f1(x0);

     if(res1==0)
     {
         cout<<endl<<"Root: "<<x0<<endl;

     }

     x1= x0-(res1/res2);

      data=(x1-x0)/x1;

    if(data<0)
    {
        data=data*(-1);
    }

     if(data<eps)
     {
          cout<<endl<<"Root: "<<x1<<endl;

     }

     else
     {
         x0=x1;
         goto lit;
     }
     return 0;
 }
