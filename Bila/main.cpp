#include <iostream>
#include <fstream>
using namespace std;

void init(int s[10][100], int niv);
int succesor(int s[10][100],int niv);
int sol(int s[10][100],int niv);
int valid(int s[10][100],int niv);
void tipar(int s[10][100],int niv);

ifstream f("date.in");
ofstream g("date.out");
int k,st[10][100],istart,jstart,n,a[100][100],m;
int jj,ii;


int main()
{
    int as,ev;
    f>>m>>n;
    f>>istart>>jstart;
    ii=istart;
    jj=jstart;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            f>>a[i][j];
    }

    for(int j=0;j<=n+1;j++)
    {   int i=0;
        a[i][j]=9999;
    }
    for(int j=0;j<=n+1;j++)
    {   int i=m+1;
        a[i][j]=9999;
    }
    for(int i=0;i<=m+1;i++)
    {   int j=0;
        a[i][j]=9999;
    }
    for(int i=0;i<=m+1;i++)
    {   int j=n+1;
        a[i][j]=9999;
    }

    st[1][1]=istart;
    st[2][1]=jstart;
    st[3][1]=4;

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
void init(int s[10][100], int niv)
{
    s[1][niv]=istart;
    s[2][niv]=jstart;
    s[3][niv]=1;
}
int succesor(int s[10][100],int niv)
{
    if(a[ii-1][jj]<a[ii][jj]){ii--;s[1][niv]=ii;s[2][niv]=jj;s[3][niv]=1;return 1;}
    else if(a[ii][jj+1]<a[ii][jj]){jj++;s[1][niv]=ii;s[2][niv]=jj;s[3][niv]=2;return 1;}
         else if(a[ii-1][jj] < a[ii][jj])  {ii--;s[1][niv]=ii;s[2][niv]=jj;s[3][niv]=3;return 1;}
            else if(a[ii][jj-1] < a[ii][jj])  {jj--;s[1][niv]=ii;s[2][niv]=jj;s[3][niv]=4;return 1;}
                 else return 0;

}
int sol(int s[10][100],int niv)
{
    if(s[1][niv]==n || s[2][niv]==m)return 1;
    else return 0;
}
int valid(int s[10][100],int niv)
{
    if(s[3][niv]<4){s[3][niv]++;return 1;}
    else {return 0;}
}
void tipar(int s[10][100],int niv)
{
    for(int j=1;j<=niv;j++)
    {
        for(int i=1;i<=3;i++)
        {
            g<<s[i][j]<<' ';
        }
        g<<endl;
    }
    g<<endl;
}

