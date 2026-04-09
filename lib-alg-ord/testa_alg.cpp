#include <iostream>

// selection sort
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


int main(){

    int tamVet;
    std::cout << "digite o tamanho do vetor: ";
    std::cin >> tamVet; 

    int* vet = new int[tamVet];

    for(int i = 0; i<tamVet; i++){
        std::cout << "digite o numero pra posicao " << i << " do vetor: ";
        std::cin >> vet[i];
    }

    std::cout << "Vetor baguncado: " ;
    for(int i = 0; i<tamVet; i++){
        std::cout << vet[i] << " ";
    }

    //selection_sort(vet, tamVet);
    //insertion_sort(vet, tamVet);

    std::cout << "Vetor Ordenado: " ;
    for(int i = 0; i<tamVet; i++){
        std::cout << vet[i] << " ";
    }

    delete[] vet;

    return 0;
}