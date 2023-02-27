#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int prior(char op)
{
    if(op=='+' || op=='-')return 1;
    else if(op=='*' || op=='/' || op=='%')return 2;
         else if(op=='(' || op==')')return 0;
}


int main()
{
    ifstream f("date.in");
    ofstream g("date.out");
    char c,st[50],FP[50],fppas=0;
    int i,j;
    i=1;
    char e[50];
    e[0]='(';
    while(f>>e[i])
    {
        i++;
    }
    e[i]=')';
    e[i+1]='\0';
    j=0;int k=1;

    while(j<=i)
    {
        if(e[j]=='('){st[k]=e[j];k++;}
        else if(e[j]=='+' || e[j]=='-'){if(prior(st[k])<prior(e[j])){st[k]=e[j];k++;}}
             else if(e[j]=='*' || e[j]=='/' || e[j]=='%'){if(prior(st[k])<prior(e[j])){st[k]=e[j];k++;}}
                  else if((e[j]>=65 && e[j]<=90) || (e[j]>=97 && e[j]<=122)){FP[fppas]=e[j];fppas++;}
                        else if(e[j]==')'){while(st[k]!='('){FP[fppas]=st[k];fppas++;k--;}}


        j++;
    }

    for(j=0;j<=i;j++)
    {
        g<<e[j];
    }
    g<<endl;
    for(j=0;j<fppas;j++)
    {
        g<<FP[j];
    }


    return 0;
}

