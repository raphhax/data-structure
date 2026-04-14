#include <iostream>

int* merge_sort(int *vet, int inicio, int fim){
    int aux, meio;
    if((fim - inicio) > 1){
        meio = (fim + inicio)/2;
        merge_sort(vet, inicio, meio);
        merge_sort(vet, meio, fim);
    }

    /*
    if(tamVet == 1){
        return vet;
    }
    for(int i = 0; i < tamVet-1; i++){
        if(vet[i] < vet[i+1]){
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
        }
    }
    return vet;
    
    int meio = tamVet/2;
    int* vet1 = new int[meio];
    vet1 = merge_sort(vet, tamVet/2);
    //vet2 = merge_sort(vet, tamVet/2);

    */
}

int* merge(int *vet, int inicio, int meio, int fim){
    int *esquerda = new int[meio];
    int *direita = new int[fim-meio];
    for(int i = 0; i < meio; i++){
        esquerda[i] = vet[i];
    }
    for(int i = meio; i < fim; i++){
        direita[i] = vet[i];
    }
}