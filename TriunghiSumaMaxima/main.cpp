#include <iostream>
#include <fstream>
#define  INFILE  "date.in"
#define  OUTFILE "date.out"
using namespace std;

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");
    int i,j,m,n;
    int a[40][40],s[40][40];
    f>>m;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=i;j++)
        {
            f>>a[i][j];
        }

    }
    int maxim;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=i;j++)
        {
        if(s[i-1][j-1]>s[i-1][j])maxim=s[i-1][j-1];
        else maxim=s[i-1][j];
        s[i][j]=a[i][j]+maxim;

        }
    }
    maxim=s[m][1];
    for(i=2;i<=j;i++)
    {
        if(maxim<s[m][i])maxim=s[m][i];

    }
    g<<maxim<<endl;


    for(i=1;i<=m;i++)
    {
        for(j=1;j<=i;j++)
        {
            g<<s[i][j]<<' ';
        }
        g<<endl;

    }


    return 0;
}
