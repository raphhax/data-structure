#include "stock.hpp"
#include <iostream>
#include <cmath>

Stock::Stock(int id, int w){
    this->id = id;
    this->w = w;
    this->cotacao = new double[w];
    double fator_janela = 1.0 / (w - 1.0);
    this->quant_precos = 0;
}

Stock::~Stock(){
    delete[] cotacao;
}


void Stock::addCotacao(double preco){

}

int Stock::getId(){
    return this->id;
}

double Stock::getRetornoElementar(int i){
    return (cotacao[i]/cotacao[i-1]) - 1;
}

double Stock::getVolatilidade(){
    sqrt(1.0/(w-1));
}

double Stock::getRET(){
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
    return (1.0/w-1.0) * somatorio;
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
    return (double)positivos / (w - 1.0);
}