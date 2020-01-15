#include<iostream>
#include<algorithm>

using namespace std;

/*
Esercizio 2.

Si proponga un algoritmo efficiente che dato un albero binario
di ricerca ed una chiave k
trovi nell'albero il nodo con la chiave più vicina a k.
Si stabilisca la complessità dell'algoritmo.
Come cambia la risposta se l'albero binario di ricerca è un RB-albero?
*/

struct nodo{
    int k;

    struct nodo *sx, *dx;

    struct nodo *new_node(int val){
        struct nodo *temp =  (struct nodo *)malloc(sizeof(struct nodo));
        temp->k = val;
        temp->sx = temp->dx = NULL;
        return temp;
    }

    void insert(int val){
        if(val<k){
            if(sx==NULL) sx = new_node(val);
            else sx->insert(val);
        }else{
            if(dx==NULL) dx = new_node(val);
            else dx->insert(val);
        }
    }

    void visit(){
        if(sx!=NULL) sx->visit();
        cout << k << " ";
        if(dx!=NULL) dx->visit();
    }

    // O(n) Linear
    int get_closest_n(int target){
        int sx_val = sx!=NULL ? sx->get_closest_n(target) : k;
        int dx_val = dx!=NULL ? dx->get_closest_n(target) : k;
        int min_val = abs(target-sx_val) < abs(target-dx_val) ? sx_val : dx_val;

        return abs(target-min_val) < abs(target-k) ? min_val : k;
    }

    // O(log n) Logarithmic
    int get_closest_logn(int target){

        auto curr = this;
        int ris = curr->k;

        while((curr->sx!=NULL || curr->dx!=NULL) && ris>0){

            if(curr->sx!=NULL && curr->k>target)
                curr = curr->sx;
            else if(curr->dx!=NULL)
                curr = curr->dx;

            ris = abs(ris-target) < abs(curr->k-target) ? ris : curr->k;
        }

        return ris;
    }

};

int main(){
    cout.tie(NULL);

    nodo radice = {10};

    radice.insert(3);
    radice.insert(14);
    radice.insert(7);
    radice.insert(19);
    radice.insert(21);

    //radice.visit(); // 3 7 10 14 19 21

    cout << radice.get_closest_logn(13); // 14

    return 0;
}
