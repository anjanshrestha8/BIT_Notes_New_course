//lab 2
//SOLUTION OF EQUATION BY BISECTION METHODS
//OBJECTIVE: TO FIND THE ROOT (REAL & POSITIVE) OF THE GIVEN EQUATION USING BISECTION METHOD (BRACKETING METHOD)
/* THEROY
ALGORITHM
READ XN AND XP AND EPS
*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define EPS 0.000001
#define F(x) (x*log(x))-1

using namespace std;

main()
{
	float xn,xp,xm,a,b,c,d;
	int count;

	begin:
	cout << ".......Enter Bracketing Values........"<<endl;
    cout<<"Enter first bracketing value: ";
	cin >> xn;
	cout<<"Enter second bracketing value: ";
	cin >> xp;

	a=F(xn);
	b=F(xp);

	if((a*b)>0)
	{
	    cout<<endl<<endl;
		printf("Entered Values Didnot Bracket The ROOT\n");
		goto begin;
	}
	else
	{
    	iteration:
		xm=((xn+xp)/2);
		c=F(xm);

		if(c==0)
		{
			cout << "\n\nROOT: " <<  xm<<endl;
		}
		else
		{
			if(c<0)
            {
                xn=xm;
            }
			else
            {
                xp=xm;
            }
            d=fabs((xn-xp)/xn);
			if(d<EPS)
			{
				xm=((xn+xp)/2);
				cout << "\n\nROOT: " <<  xm<<endl;
  			}
			else
			{
				goto iteration;
			}
		}
	}
}
