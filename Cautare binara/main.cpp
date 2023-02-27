#include <iostream>

using namespace std;

int cautare_binara_clasic(int n,int l){


    int s,d,mid;
    s=0;
    d=l;
    while(s<=d)
    {
        mid=(s+d)/2;
        if(mid==n){cout<<mid;break;}
        if(n<mid)d=mid-1;
        if(n>mid)s=mid+1;
    }

}
int main()
{
    int n,s,d,l,mid;
    cin>>l>>n;
    s=0;
    d=l;
    while(s<=d)
    {
        mid=(s+d)/2;
        if(mid==n){cout<<mid;break;}
        if(n<mid)d=mid-1;
        if(n>mid)s=mid+1;
    }

    return 0;
}
