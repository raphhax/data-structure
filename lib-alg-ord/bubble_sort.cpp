void bubble_sort(int* vet, int tamVet){
    int aux = 0, limite = (tamVet-1);
    bool ordenado = false;
    while(!ordenado){
        ordenado = true;
        for(int i = 0; i < limite; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                ordenado = false;
            }
        }
        limite--;
    }
}