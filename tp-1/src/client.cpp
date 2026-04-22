#include "client.hpp"
#include <iostream>

Client::Client(int id) {
    this->id = id;
    this->carteira = nullptr;
}

Client::~Client() {
    noAcoes* atual = carteira;
    while (atual != nullptr) {
        noAcoes* proximo = atual->proximo_no;
        delete atual;
        atual = proximo;
    }
}

void Client::compra_acao(int id_acao) {
    noAcoes* novo = new noAcoes;
    novo->id_acao = id_acao;
    novo->proximo_no = carteira;
    carteira = novo;
}

void Client::vende_acao(int id_acao) {
    noAcoes* atual = carteira;
    noAcoes* anterior = nullptr;
    while (atual != nullptr) {
        if (atual->id_acao == id_acao) {
            if (anterior == nullptr) {
                carteira = atual->proximo_no;
            } else {
                anterior->proximo_no = atual->proximo_no;
            }
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->proximo_no;
    }
}

int Client::getId() {
    return this->id;
}

noAcoes* Client::getCarteira() {
    return this->carteira;
}