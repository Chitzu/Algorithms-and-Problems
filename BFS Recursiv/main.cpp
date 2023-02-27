#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int prim=1,ultim=1,n,nd,c[100],viz[100],varf,a[100][100];

void bf_recursiv()
{
    int k;
if(prim<=ultim)
    {varf=c[prim];

   for(k=1;k<=n;k++)
      if(a[varf][k]==1&&viz[k]==0)

            {ultim++;

             c[ultim]=k;

             viz[k]=1;
            }

  prim++;

  bf_recursiv();

      }

}
int main()
{
    f>>n;int x,y;
    f>>nd;
 viz[nd]=1;
 c[prim]=nd;
    while(f>>x>>y)
    {
        a[x][y]=1;
        a[y][x]=1;
    }
    bf_recursiv();
     for(int i=1;i<=ultim;i++)
        g<<c[i]<<" ";
    return 0;
}
