#include <iostream>
#include <string>
#include "system.hpp"

using namespace std;

int main() {
    System* sistema = nullptr;
    char comando;

    while (cin >> comando) {        
        if (comando == 'M') {
            int w;
            cin >> w;
            string resto_linha;
            getline(cin, resto_linha);
            sistema = new System(w);
        }
        else if (comando == 'A') {
            int id_acao;
            cin >> id_acao;
            if (sistema) sistema->criaAcao(id_acao);
        }
        else if (comando == 'U') {
            int id_cliente;
            cin >> id_cliente;
            if (sistema) sistema->criaCliente(id_cliente);
        }
        else if (comando == 'P') {
            int id_acao;
            double preco;
            cin >> id_acao >> preco;
            if (sistema) sistema->atualizaPreco(id_acao, preco);
        }
        else if (comando == 'B') {
            int id_cliente, id_acao;
            cin >> id_cliente >> id_acao;
            if (sistema) sistema->compraAcao(id_cliente, id_acao);
        }
        else if (comando == 'V') {
            int id_cliente, id_acao;
            cin >> id_cliente >> id_acao;
            if (sistema) sistema->vendeAcao(id_cliente, id_acao);
        }
        else if (comando == 'Q') {
            int id_consulta, id_cliente, n_retorno, m_metricas;
            cin >> id_consulta >> id_cliente >> n_retorno >> m_metricas;

            string* nomes_metricas = new string[m_metricas];
            double* pesos = new double[m_metricas];

            for (int i = 0; i < m_metricas; i++) {
                cin >> nomes_metricas[i] >> pesos[i];
            }
            if (sistema) {
                sistema->realizaConsulta(id_consulta, id_cliente, n_retorno, m_metricas, nomes_metricas, pesos);
            }

            delete[] nomes_metricas;
            delete[] pesos;
        }
    }
    if (sistema != nullptr) {
        delete sistema;
    }
    return 0;
}