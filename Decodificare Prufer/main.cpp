#include <iostream>

using namespace std;

int n;
int cp[100];
int v[100];

int valid(int x,int poz)
{
    for(int i=poz+1;i<=n-2;i++)
    {
        if(cp[i]==x)return 0;
    }
    return 1;
}

int muchie(int x,int poz)
{
    for(int i=1;i<=n;i++)
    {
        if(valid(v[i],poz)==1 && v[i]!=0 && x!=v[i]){v[i]=0;return i;}
    }
}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        v[i]=i;
    }
    for(int i=1;i<=n-2;i++)
    {
        cin>>cp[i];
    }
    int i,j;
    for(i=1;i<=n-2;i++)
    {
        j=muchie(cp[i],i);
        cout<<cp[i]<<' '<<'-'<<' '<<j<<endl;
    }

    return 0;
}
