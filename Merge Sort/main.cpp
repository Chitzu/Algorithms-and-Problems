#include <iostream>

using namespace std;

void interclasare(int vect[100],int st,int mij,int dr)
{
	int aux[100],ist,j=mij+1,k=1;
    while(ist<=mij && j<=dr)
    {
        if(vect[ist]<vect[j]){aux[k]=vect[ist];ist++;}
        else {aux[k]=vect[j];j++;}
        k++;

    }
    if(ist>mij)for(int i=j;i<=dr;i++){vect[k]=vect[i];k++;}
       else for(int i=ist;i<=mij;i++){vect[k]=vect[i];k++;}

    for(int i=1;i<=k;i++){vect[i]=aux[i];}
}

void merge_sort(int vec[100],int s,int d)
{
	int mij=(s+d)/2;

	if(d>s){
            merge_sort(vec,s,mij);
            merge_sort(vec,mij+1,d);
            interclasare(vec,s,mij,d);
	}

}


int main()
{
    int n,v[100];
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }

    merge_sort(v,1,n);

    for(int i=1;i<=n;i++)
    {
        cout<<v[i];
    }
    return 0;
}
