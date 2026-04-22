#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "stock.hpp"
#include "client.hpp"
#include <string>

class System {
    
private:
    Stock** acoes;
    Client** clientes;
    
    int capacidade_acoes;
    int capacidade_clientes;
    int num_acoes;
    int num_clientes;
    int janela_w;
    void quickSort(double* valores, int* ids, int esq, int dir);

public:
    System(int w);
    ~System();

    void criaAcao(int id_acao);
    void criaCliente(int id_cliente);
    void atualizaPreco(int id_acao, double preco);
    void compraAcao(int id_cliente, int id_acao);
    void vendeAcao(int id_cliente, int id_acao);
    void realizaConsulta(int id_consulta, int id_cliente, int n_retorno, int m_metricas, std::string* nomes_metricas, double* pesos);
};

#endif