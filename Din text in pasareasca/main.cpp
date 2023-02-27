#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
    char s[100],vocala;
    int i,j,n;
    ifstream f("date.in");
    ofstream g("date.out");
    f>>s;
    n=strlen(s);
    s[n+1]='\0';
    for(i=0;i<n;i++)
    {
        switch(s[i])
            {
            case 97 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 101 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 105 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 111 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 117 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 65 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 69 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 73 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 79 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;
            case 85 : for(j=n;j>i;j--){s[j+3]=s[j+2];s[j+2]=s[j+1];} s[i+1]='p';s[i+2]=s[i]; i=i+3;break;

            }
    }

    g<<s;

    return 0;
}
