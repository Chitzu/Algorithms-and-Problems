#include <iostream>

using namespace std;

    struct elem{int inf; elem *au;};
    elem *prim,*c,*ultim;

int main()
{
    char rasp;
    int x,v[50];

    cout<<"introdu prima informatie: ";
    cin>>x;
    prim= new elem;
    prim->inf=x;
    v[1]=x;
    prim->au=NULL;
    ultim=prim;
    cout<<"Mai introduci?";
    cin>>rasp;
    int i=2;
    while(rasp!='n')
    {
        cin>>x;
        v[i]=x;i++;
        c=new elem;
        c->inf=x;
        c->au=NULL;
        ultim->au=c;
        cout<<"Mai introduci?";
        cin>>rasp;
    }

    for(int j=1;j<=i;j++)
    {
        cout<<v[j]<<' ';
    }

    return 0;
}
