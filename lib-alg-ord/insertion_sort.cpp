void insertion_sort(int* vet, int tamVet){
    int aux = 0, j;
    for(int i = 1; i < tamVet; i++){
        j = i;
        while(j >= 1 && (vet[j-1] > vet[j])){
            aux = vet[j-1];
            vet[j-1] = vet[j];
            vet[j] = aux;
            j--;
        }
        
    }
}
