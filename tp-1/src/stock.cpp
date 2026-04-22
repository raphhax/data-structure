#include "stock.hpp"
#include <iostream>
#include <cmath>

Stock::Stock(int id, int w){
    this->id = id;
    this->w = w;
    this->cotacao = new double[w];
    this->fator_janela = 1.0 / (w - 1.0);
    this->quant_precos = 0;
}

Stock::~Stock(){
    delete[] cotacao;
}


void Stock::addCotacao(double preco) {
    if (quant_precos < w) {
        cotacao[quant_precos] = preco;
        quant_precos++;
    } else {
        for (int i = 0; i < (w - 1); i++) {
            cotacao[i] = cotacao[i + 1];
        }
        cotacao[w - 1] = preco;
    }
}

int Stock::getId(){
    return this->id;
}

double Stock::getRetornoElementar(int i){
    if (i <= 0){
        return 0.0;
    }
    return (cotacao[i]/cotacao[i-1]) - 1;
}

double Stock::getVolatilidade(){
    return sqrt(1.0/(w-1));
}

double Stock::getRET(){
    if (quant_precos < w){
        return 0.0;
    }
    return (cotacao[w-1] / cotacao[0]) - 1;
}

double Stock::getAVGRET(){
    if(quant_precos < w){
        return 0.0;
    }
    double somatorio = 0;
    for(int i = 1; i < w; i++){
        somatorio+=getRetornoElementar(i);
    }
    return somatorio / (w-1.0);
}

double Stock::getSTAB(){
    if (quant_precos < w){
        return 0.0;
    }
    double media = getAVGRET();
    double somatorio_quadrados = 0;
    for (int i = 1; i < w; i++) {
        double ret_elementar = getRetornoElementar(i);
        somatorio_quadrados += pow(ret_elementar - media, 2);
    }
    double vol = sqrt(somatorio_quadrados / (w - 1.0));
    return 1.0 / (1.0 + vol);
}

double Stock::getCONS() {
    if (quant_precos < w){
        return 0.0;
    }
    int positivos = 0;
    for (int i = 1; i < w; i++) {
        if (getRetornoElementar(i) > 0) positivos++;
    }
    return (double)positivos/(w - 1.0);
}