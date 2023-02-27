#include <iostream>
#include <math.h>
using namespace std;
void init(int s[100], int niv);
int succesor(int s[100],int niv);
int sol(int S[100],int niv);
int valid(int s[100],int niv);
int k,st[100],n,lg;
void tipar(int s[100],int niv);
int main()
{
    int as,ev;
    cin>>n>>lg;
    st[1]=n;
    k=2;
    init(st,k);
    while(k>0)
    {
        do
        {
            as=succesor(st,k);
            ev=valid(st,k);
        }
        while(as && !ev);
        {
            if(as)
            {
                if(sol(st,k))
                {
                    tipar(st,k);
                }
                else
                {
                    k++;
                    init(st,k);
                }
            }
            else k--;
        }
    }
    return 0;
}
void init(int s[100], int niv)
{
    if(niv==lg)s[niv]=n;
    else s[niv]=0;
}
int succesor(int s[100],int niv)
{

    if(s[niv]==lg-1)return 0;
    else {s[niv]++;return 1;}
}
int sol(int s[100],int niv)
{
    return (niv==lg);
}
int valid(int s[100],int niv)
{
    int i;
    if(abs(s[niv-1]-s[niv])==1)return 1;
    else return 0;

}
void tipar(int s[100],int niv)
{
    for(int i=1; i<=niv; i++)
        cout<<s[i]<<' ';
    cout<<endl;
}

