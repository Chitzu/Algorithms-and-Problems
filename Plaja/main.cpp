#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("plaja.in");
    ofstream g("plaja.out");
    int m,n;
    f>>n>>m;
    int plaja[20][20];
    int arie[20],k=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            f>>plaja[n][m];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(plaja[i][j]==0){
                    int lat2=0;int bb=j;int aa=i;
                    while(bb<=m && bb!=1)
                    {
                        lat2++;
                        bb++;
                    }
                    int lat1=0;
                    while(aa<=n && aa!=1)
                    {
                        lat1++;
                        aa++;
                    }
                    arie[k]=lat1*lat2;
                    k++;


            }
        }
    }
    int maxx=arie[1];
    for(int i=2;i<k;i++)
    {
        if(arie[i]>maxx)maxx=arie[i];
    }
    g<<maxx;
    return 0;
}

