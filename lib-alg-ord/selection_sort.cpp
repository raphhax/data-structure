#include <iostream>

void selection_sort(int* vet, int tamVet){
    int indMin, aux;
    for(int i = 0; i < tamVet; i++){
        indMin = i;
        for(int j = i; j < tamVet; j++){
            if(vet[j] < vet[indMin]){
                indMin = j;
            }
        }
        if(vet[i] > vet[indMin]){
            aux = vet[i];
            vet[i] = vet[indMin];
            vet[indMin] = aux;
        }
    }
}