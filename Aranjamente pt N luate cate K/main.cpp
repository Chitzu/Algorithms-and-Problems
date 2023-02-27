#include <iostream>

using namespace std;
int fact(int x)
{
    if(x==0 )return 1;
    if(x < 0)return 0;
    return x*fact(x-1);
}
int main()
{
    int n , k;
    cin>>n>>k;
    cout << fact(n)/fact(n-k);

    return 0;
}
