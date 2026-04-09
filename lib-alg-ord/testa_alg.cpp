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

// insertion sort
void insertion_sort(int* vet, int tamVet){
    int aux = 0, j;
    for(int i = 1; i < tamVet; i++){
        // pego posicao 0 e 1, avalio se eh menor ou nao, se for menor eu inverto, dai dps eu olho para o 2 e o 1, avalio se eh menor 
        // se for menor eu inverto os dois, depois olho esse novo indice dele e olho com o mais antigo, se for menor eu inverto,
        // ai vou pro 3 e 2, se for menor eu inverto, dai o 2 vira 3 e o 3 vira dois, ai eu olho o 2 com o 1 e analiso, se for menor eu inverto
        // e depois eu olho o 1 e o 0, se for menor eu inverto, entao basicamente eu vou mudando eles ate chegar o ultimo. Eu preciso guardar i e j
        // para olhar oq eu to e olhar o antigo, dai eu vou subtraindo 1 de cada ou pegando de um dos indeces e passando
        // para o lado, subtraindo 1 dele, até chegar em zero ou enquanto ele for maior que o do indice negativo, ai eu vou subtraindo esse indice negativo
        j = i;
        while(j >= 1 && (vet[j-1] > vet[j])){
            aux = vet[j-1];
            vet[j-1] = vet[j];
            vet[j] = aux;
            j--;
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
    insertion_sort(vet, tamVet);

    std::cout << "Vetor Ordenado: " ;
    for(int i = 0; i<tamVet; i++){
        std::cout << vet[i] << " ";
    }

    delete[] vet;

    return 0;
}