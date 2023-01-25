#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

int precedency (char);
void algo(int typ);

void algo(int typ)
{
    int i,otos=-1,ptos=-1,l,j=0,bra1,bra2;
    char poststack[100],opstack[100];
    string infix;

    cout<<"Enter a valid infix: ";
    cin>>infix;

    l=strlen(infix.c_str());

    if(typ==2)
    {
        reverse(infix.begin(),infix.end());

        bra1=41;
        bra2=40;

    }
    else
    {
        bra1=40;
        bra2=41;

    }

    for(i=0;i<=l-1;i++)
    {
         if(infix[i]==bra1)
         {
             opstack[++otos] = infix[i];
             cout<<"Enter1";
         }
         else if(isalpha(infix[i]) || (infix[i]>= 48 && infix[i]<= 57))
         {
             poststack[++ptos]=infix[i];
         }
         else if(infix[i]=='*' ||infix[i]=='/' ||infix[i]=='+' ||infix[i]=='-' ||infix[i]=='%' ||infix[i]=='$' )
         {
             if(precedency(opstack[otos])> precedency (infix[i]))
             {
                    poststack[++ptos]=opstack[otos--];
                    opstack[++otos]=infix[i];


             }
             opstack[++otos]=infix[i];
         }
         else if(infix[i]==bra2)
         {
             cout<<"Enter2";
             while(opstack[otos] != bra1)
             {
                 cout<<"Enter";
                 poststack[++ptos]=opstack[otos];
                 otos--;
             }
             otos--;
         }

    }
    while(otos!=-1)
    {
        poststack[++ptos]=opstack[otos];
        otos--;
    }

if(typ==1)
{
    cout<<endl<<endl<<"The equivalent postfix expression is: ";
    for(i=0;i<l;i++)
    {
        cout<<" "<<poststack[i];
    }

}
else
{
    cout<<endl<<endl<<"The equivalent prefix expression is: ";
    for(i=l-1;i>=0;i--)
    {
        cout<<" "<<poststack[i];
    }
}
cout<<endl<<endl;

}
int precedency (char c)
{
    switch(c)
    {
    case'$':
        return(4);
    case'*':
    case'/':
        return(3);
    case'+':
    case'-':
        return(1);
    }
}
int main()
{
    int ch;
    cout<<"1. Postfix"<<endl;
    cout<<"2. Prefix"<<endl;
    cin >> ch;
    switch(ch)
        {
        case 1:
            {
                algo(1);
                break;
            }
        case 2:
            {
                algo(2);
                break;
            }

        }
    return 0;
}
