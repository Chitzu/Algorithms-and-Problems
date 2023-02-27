#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");

int s[100],vec[100];
int NrCTC=0,n;
int viz[100];
int G[100][100];
int GT[100][100];
int k=0;

void DFS(int nod)
{
    viz[nod]=1;
    for(int i=1;i<=n;i++)
    {
        if(G[nod][i]==1 && viz[i]==0){DFS(i);};
    }
    k++;s[k]=nod;
}
void DFST(int nod)
{
    viz[nod]=1;
    for(int i=1; i<=n; i++)
    {
        if(GT[nod][i]==1 && viz[i]==0)DFST(i);
    }

}

void arata_tabel()
{
    for(int i=n; i>0; i--)
    {
        cout<<s[i];
    }
    cout<<" ";
}
void citire()
{
    int v1,v2;
    f>>n;
    while(f>>v1>>v2)
    {
        G[v1][v2]=1;
        GT[v2][v1]=1;
    }
}

void init_viz()
{
    int i;
    for(i=1; i<=n; i++)
    {
        viz[i]=0;


    }
}

int main()
{
    citire();
    DFS(1);
    arata_tabel();
    init_viz();
    for(int i=k;i>0;i--)
    {
        if(viz[s[i]]==0){NrCTC++;DFST(s[i]);};
    }
    cout<<NrCTC;
    return 0;
}
