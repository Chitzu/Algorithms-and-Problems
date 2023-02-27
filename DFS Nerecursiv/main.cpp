#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int viz[100],a[100][100],n,s[100];
int vizitat()
{
    for(int i=1;i<=n;i++)
    {
        if(viz[i]==0)return 1;
    }
    return 0;
}
int adiacent(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(a[x][i]==1 && viz[i]==0)return i;
    }
    return 0;
}
int main()
{
    int k=1,ns,i,x,y;
    f>>n;
    f>>ns;
    while(f>>x>>y)
    {
        a[x][y]=1;
        a[y][x]=1;
    }

    viz[ns]=1;
    g<<ns;
    s[k]=ns;
    while(vizitat()!=0)
    {
        i=adiacent(s[k]);
        if(i!=0){k++;s[k]=i;viz[i]=1;g<<i;}
        else k--;
    }


    return 0;
}
