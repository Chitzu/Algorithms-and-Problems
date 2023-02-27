#include <iostream>
#include <fstream>

using namespace std;

ifstream f("componenteconexe.in");
ofstream g("componenteconexe.out");

int viz[101],a[101][101],n,nrc,s=0;

void citire()
{
    f>>n;
    int i,j;
    while(f>>i>>j)
    {
        a[i][j]=1;
        a[j][i]=1;
    }
}

void DFS(int x)
{
    viz[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[x][i]==1 && viz[i]==0)DFS(i);
    }
}

void nr_muchii(int x)
{

    for(int i=1;i<=n;i++)
    {
        if(a[x][i]==1){s++;a[i][x]=0;}
    }

}
int main()
{
    citire();
    for(int i=1;i<=n;i++)
    {
        if(viz[i]==0){DFS(i);nrc++;}
    }
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=n;i++)
        {
            if(viz[i]==j){nr_muchii(i);}
        }
    }
    int del;
    del=s-n+nrc;
    g<<del;

    return 0;
}
