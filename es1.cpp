#include<iostream>
#include<algorithm>

using namespace std;

/*
Esercizio I.

Proporre un algoritmo asintoticamente lineare per
selezionare in un any non ordinato
gli elementi che nell'ordinamento occuperebbero
le posizioni n, n/2, n/4, n/8 ..
*/

void printLog(int arr[],int pos,int N){
    if(pos>N || pos <0)
        return;

    while(pos>0){
        cout << arr[pos] << " ";
        pos/=2;
    }
    cout << arr[pos] << " ";

}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

    printLog(arr,20,21);

    return 0;
}
