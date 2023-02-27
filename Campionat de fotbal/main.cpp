// CAMPIONAT DE FOOTBALL
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct echipa_football{char nume[500];int g_primite;int g_date; int puncte;}echipa[50];


int main()
{
    int k,n;
    ifstream f("date.in");
    ofstream g("date.out");
    f>>k;
    f>>n;
    char a;
    for(int i=0;i<=(k/2);i+=2)
    {
        f>>echipa[i].nume>>echipa[i].g_date;

        f>>a;

        f>>echipa[i+1].g_date>>echipa[i+1].nume;

        echipa[i].g_primite+=echipa[i+1].g_date;
        echipa[i+1].g_primite+=echipa[i].g_date;

        if(echipa[i].g_date>echipa[i+1].g_date)echipa[i].puncte+=3;
        else if(echipa[i].g_date<echipa[i+1].g_date)echipa[i+1].puncte+=3;
             else {echipa[i].puncte++;echipa[i+1].puncte++;}

    }

    char c[200];int gol;int j1,j2;

    for(int j=0;j<n-(k/2);j++)
    {
        f>>c;

        j1=0;
        while(strcmp(c,echipa[j1].nume)!=0)
        {
            j1++;
        }
        f>>gol;
        echipa[j1].g_date+=gol;

        f>>a;
        f>>gol;
        f>>c;

        j2=0;
        while(strcmp(c,echipa[j2].nume)!=0)
        {
            j2++;
        }
        echipa[j2].g_date+=gol;

        echipa[j2].g_primite+=echipa[j1].g_date;
        echipa[j1].g_primite+=echipa[j2].g_date;

        if(echipa[j1].g_date>echipa[j2].g_date)echipa[j1].puncte+=3;
        else if(echipa[j1].g_date<echipa[j2].g_date)echipa[j2].puncte+=3;
             else {echipa[j1].puncte++;echipa[j2].puncte++;}


    }
    int i;
    for(i=0;i<k;i++)
    {
       g<<echipa[i].nume<<" "<<echipa[i].puncte<<" "<<echipa[i].g_date<<" "<<echipa[i].g_primite<<endl;

    }


    return 0;
}


