#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");
    int n,j=0,ok;
    char s[20];
    int slen;
    f>>n;
    int i,k;
    int st,dr;
    for(i=0;i<n;i++)
    {
        f.getline(s,20);
        slen=strlen(s);
        ok=0;
        for(j=0;j<slen;j++)
        {

            if(s[j]=='('){for(k=j;k<slen;j++)
                            {
                                if(s[k]==')'){ok=1;st=k;dr=slen;while(st!=dr){s[st]=s[st+1];dr--;} while(k!=dr){s[k]=s[k+1];dr--;}slen=dr; break;}
                            }
                         }
            if(s[j]=='(')ok=0;
        }
        g<<ok<<endl;
    }




    return 0;
}
