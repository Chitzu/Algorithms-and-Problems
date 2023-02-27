#include <iostream>

using namespace std;

void init(int s[100],int niv);
int succesor(int s[100],int niv);
int valid(int s[100],int niv);
int sol(int s[100],int niv);
void tiparire(int s[100],int j);

int n,st[100],m,k;int j;

int main()
{
    int as,ev;
    cin>>n>>m;
    k=1;
    init(st,k);
    while(k>0)
    {
        do
        {
            as=succesor(st,k);
            ev=valid(st,k);

        }
        while(as && !ev);
        if(as){if(sol(st,k))tiparire(st,k);
               else {j++;init(st,k);}
              }
        else k--;

    }
    return 0;
}
void init(int s[100],int niv)
{
    s[niv]==0;
}
int succesor(int s[100],int niv)
{
    int c,a;
    for(int i=1;i<=niv;i++)
    {
        if(s[i]==1)c++;
        else if(s[i]==2)a++;
    }
    if(c==m && a==n)return 0;
    else return 1;
}
int valid(int s[100],int niv)
{
    if(s[niv-1])
}
int sol(int s[100],int niv)
{
    return (niv==k);
}
void tiparire(int s[100],int niv)
{
    for(int i=1; i<=niv; i++)
        cout<<s[i]<<' ';
    cout<<endl;
}


