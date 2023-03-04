#include <iostream>
#include "Queue.h"
#include <string>
#include <fstream>

using namespace std;

//Tema 2

int main()
{
	
	ifstream f("input.in");
	int timp_inceput, timp, pret, P, C, D, B;
	int produse = 0;
	int CB = 0;
	int client = 1;
	int timpCB = 0;
	int produsB = 0;
	int bifat = 0;
	string produs,caracter;
	cin >> P >> C >> D >> B;


	Queue<int> Q;
	while (cin >> timp_inceput)
	{
		

		if(client == 1)timp = timp_inceput;
		int maxim = 0;
		int ok = 0;
		int suma = 0;
		while (cin >> produs && produs != "T" && cin>>pret)
		{
			
			produse++;
			if (produse % P == 0 && ok == 0) { ok = 1;
				if (produsB < B) {
					produsB++;
				}
			
			}  // P
			if (client %C==0 )ok = 2;					//C
			suma += pret;
			
				if (client % C == 0 && produse % P == 0) { ok = 3; 
			if (produsB < B) {
				produsB++;
			}
			}
			timp += 3;
			if (produsB == B && bifat == 0) {		//B
				timpCB = timp;
			//	cout << produs << " ";
				bifat = 1;
				//cout <<"prod: " << produse <<"pret: " << pret << " " <<timp <<endl;
			}	
			
			if (pret > maxim)maxim = pret;
			
		
			
		
		}

		//	cout <<client<<" "<< timp<<endl;
		

		if (ok == 3) {
			maxim = maxim * 1 / 2;
			if (suma >= D)suma = D;
			if (suma > maxim) {
				maxim = 0;
			}
			else { suma = 0; }
		}
		else {
			if (ok == 1) { maxim = maxim * 1 / 2;  }
			else maxim = 0;

			if (ok == 2) {
				if (suma >= D)suma = D;
			}
			else suma = 0;
				
			
		}
		
		if (bifat == 1 && timp_inceput<timpCB )
		{
			CB++;
		//	cout << "timpCB: " << timpCB<<" " << "timp: " << timp << endl;
		//	cout << client << endl;
		}
		client++;
		Q.push(maxim, suma, timp - timp_inceput);
	}
	
	
//	Q.afisare();
	cout << CB<<" ";
	Q.Prelucrare();

	return 0;
}