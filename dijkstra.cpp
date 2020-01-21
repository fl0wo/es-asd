#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <climits>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

#define MAXN 10000+1

typedef long long ll;
typedef pair<ll,ll> pll;

/*
Grafo implementato come lista di liste di coppie.
grafo[i] -> mi dice il nodo i con quali nodi è collegato,
e con quale peso.
*/
vector<vector<pll>> grafo(MAXN);

set <pll> coda; //coda
vector <ll> d(MAXN,LLONG_MAX); //vettore delle distanze
bool b[MAXN];  // vettore visited

set<pll> :: iterator it;
set<pll> :: iterator itt;

void dijkstra();

ll n=2; // ci sono 2 nodi
ll m=1; // c'è 1 arco
ll s=1; // runno dijkstra partendo dal nodo 1
ll f=2; // e mi interessa il path per arrivare al 2

int main(){
    grafo[1].push_back(make_pair(1,2)); //orientato
    //grafo[a].push_back(make_pair(peso,da));

    dijkstra();

    // stampa la minima distanza per arrivare ad f
	cout << d[f];
}

void dijkstra(){
    // parto dal source
    d[s] = 0; // la distanza per arrivare da dove parto è 0
	b[s] = true; // diciamo che il primo nodo l'abbiamo visitato

	// inseriamolo nella coda
	coda.insert(make_pair(0,s));

	long long x,y,z;

	// fino a quando la coda non è vuota
	while(!coda.empty()){

        // prendo l'elemento in testa
		it=coda.begin();

		// il nodo (inizialmente source s)
		x = (*it).second;

		// rimuovo il nodo precedente dalla coda
		coda.erase(it);

		// vado a vedere tutti i "figli" del nodo s
		for(int i=0;i<grafo[x].size();i++){

			y = grafo[x][i].second; // nodo collegato
			z = grafo[x][i].first; // peso con la quale è collegato

			// cerco se ho già precedentemente calcolato la min dist per y
			itt=coda.find(make_pair(d[y],y));

			// vedo se la distanza precedentemente calcolata
			// è maggiore di quella current
			if(d[y]>d[x]+z){

                // se si, vuol dire che si può fare di meglio
                d[y] = d[x]+z;

                // controllo se avevo già visitato y
                // in casi la vecchia distanza
                if(b[y]) coda.erase(itt);
                else b[y]=true;

                // e inserisco quella nuova, più bassa
                coda.insert(make_pair(d[y],y));
            }
		}
	}
}
