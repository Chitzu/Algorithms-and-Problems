#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("bila.out");

void init();
int succesor();
int valid();
void tipar();
int sol();

int n, m, k, st[4][20], as, a[12][12], i_branza, j_branza, solutie = 0;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f >> a[i][j];
        }
    }

    for (int i = 0; i <= n + 1; i++)
    {
        a[0][i] = 1;
        a[m + 1][i] = 1;
    }
    for (int i = 0; i <= m + 1; i++)
    {
        a[i][0] = 1;
        a[i][n + 1] = 1;
    }

    k = 1;
    f >> st[1][k] >> st[2][k];
    f >> i_branza >> j_branza;
    init();
    k = 2;
    while (k > 1)
    {
        do
        {
            as = succesor();
        } while (as && !valid());
        if (as)
            if (sol())
            {
                solutie++;

            }
            else
            {
                k++;
                init();
            }
        else { a[st[1][k]][st[2][k]] = 0; k--; }
    }
    cout << solutie;
    return 0;
}

void init()
{
    st[3][k] = 0;
}

int succesor()
{
    if (st[3][k] == 4) return 0;
    else
    {
        st[3][k]++;
        if (st[3][k] == 1)
        {
            st[1][k] = st[1][k - 1] - 1;
            st[2][k] = st[2][k - 1];
            return 1;
        }
        else if (st[3][k] == 2)
        {
            st[2][k] = st[2][k - 1] + 1;
            st[1][k] = st[1][k - 1];
            return 1;
        }
        else if (st[3][k] == 3)
        {
            st[1][k] = st[1][k - 1] + 1;
            st[2][k] = st[2][k - 1];
            return 1;
        }
        else if (st[3][k] == 4)
        {
            st[2][k] = st[2][k - 1] - 1;
            st[1][k] = st[1][k - 1];
            return 1;
        }
    }
    return 0;

}

int valid()
{
    if (a[st[1][k]][st[2][k]] == 0) { a[st[1][k]][st[2][k]] = 1; return 1; }
    else return 0;
}

int sol()
{

    if (st[1][k] == i_branza && st[2][k] == j_branza )return 1;
    else return 0;
}


void tipar()
{
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}
