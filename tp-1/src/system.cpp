#include "system.hpp"
#include <iostream>
#include <iomanip>

System::System(int w) {
    this->janela_w = w;
    
    // Utilizei como estratégia adotar uma quantidade básica inicial de ações e clientes que seriam passados, 
    // para evitar operações de alocação de memória em excesso
    this->capacidade_acoes = 10;
    this->capacidade_clientes = 10;
    this->num_acoes = 0;
    this->num_clientes = 0;

    this->acoes = new Stock*[capacidade_acoes];
    for (int i = 0; i < capacidade_acoes; i++) {
        acoes[i] = nullptr;
    }

    this->clientes = new Client*[capacidade_clientes];
    for (int i = 0; i < capacidade_clientes; i++) {
        clientes[i] = nullptr;
    }
}

System::~System() {
    for (int i = 0; i < capacidade_acoes; i++) {
        if (acoes[i] != nullptr) {
            delete acoes[i]; 
        }
    }
    delete[] acoes;
    for (int i = 0; i < capacidade_clientes; i++) {
        if (clientes[i] != nullptr) {
            delete clientes[i];
        }
    }
    delete[] clientes;
}

void System::criaAcao(int id_acao) {
    if (id_acao >= capacidade_acoes) {
        int nova_capacidade = capacidade_acoes * 2;

        if (id_acao >= nova_capacidade) nova_capacidade = id_acao + 1; 

        Stock** novo_array = new Stock*[nova_capacidade];       
        
        for (int i = 0; i < capacidade_acoes; i++) novo_array[i] = acoes[i];

        for (int i = capacidade_acoes; i < nova_capacidade; i++) novo_array[i] = nullptr;   

        delete[] acoes;
        acoes = novo_array;
        capacidade_acoes = nova_capacidade;
    }
    if (acoes[id_acao] == nullptr) {
        acoes[id_acao] = new Stock(id_acao, janela_w);
        if (id_acao >= num_acoes) num_acoes = id_acao + 1;
    }
}

void System::criaCliente(int id_cliente) {
    if (id_cliente >= capacidade_clientes) {
        int nova_capacidade = capacidade_clientes * 2;

        if (id_cliente >= nova_capacidade) nova_capacidade = id_cliente + 1;
        
        Client** novo_array = new Client*[nova_capacidade];
        
        for (int i = 0; i < capacidade_clientes; i++) novo_array[i] = clientes[i];
        
        for (int i = capacidade_clientes; i < nova_capacidade; i++) novo_array[i] = nullptr;
        
        delete[] clientes;
        clientes = novo_array;
        capacidade_clientes = nova_capacidade;
    }

    if (clientes[id_cliente] == nullptr) {
        clientes[id_cliente] = new Client(id_cliente);
        if (id_cliente >= num_clientes) num_clientes = id_cliente + 1;
    }
}

void System::atualizaPreco(int id_acao, double preco) {
    if (id_acao < capacidade_acoes && acoes[id_acao] != nullptr) {
        acoes[id_acao]->addCotacao(preco);
    }
}

void System::compraAcao(int id_cliente, int id_acao) {
    if (id_cliente < capacidade_clientes && clientes[id_cliente] != nullptr) {
        clientes[id_cliente]->compra_acao(id_acao);
    }
}

void System::vendeAcao(int id_cliente, int id_acao) {
    if (id_cliente < capacidade_clientes && clientes[id_cliente] != nullptr) {
        clientes[id_cliente]->vende_acao(id_acao);
    }
}

// Implementacao do quick sort usando o elemento do meio como pivô, a fim de evitar O(Nˆ2).
void System::quickSort(double* valores, int* ids, int esq, int dir) {
    if (esq >= dir) return;
    int i = esq, j = dir;
    int pivo_idx = esq + (dir - esq) / 2;
    double pivo_val = valores[pivo_idx];
    int pivo_id = ids[pivo_idx];

    while (i <= j) {
        while (valores[i] > pivo_val || (valores[i] == pivo_val && ids[i] < pivo_id)) {
            i++;
        }
        while (valores[j] < pivo_val || (valores[j] == pivo_val && ids[j] > pivo_id)) {
            j--;
        }
        if (i <= j) {
            double temp_v = valores[i]; 
            valores[i] = valores[j]; 
            valores[j] = temp_v;
            int temp_id = ids[i]; 
            ids[i] = ids[j]; 
            ids[j] = temp_id;
            i++; 
            j--;
        }
    }
    
    quickSort(valores, ids, esq, j);
    quickSort(valores, ids, i, dir);
}

void System::realizaConsulta(int id_consulta, int id_cliente, int n_retorno, int m_metricas, std::string* nomes_metricas, double* pesos) {   
    double* pontuacao_final = new double[num_acoes];
    
    for (int i = 0; i < num_acoes; i++) {
        pontuacao_final[i] = 0.0;
    }
    
    int* ids_temp = new int[num_acoes];
    double* valores_temp = new double[num_acoes];
    
    // Há um for dentro de outro, entretando não gera impacto significativo na complexidade, uma vez que o for de fora
    // passa apenas por pequenos valores, relativos às métricas que iremos analisar, portanto em baixíssima escala dado
    // ser uma constante, e o outro for ele roda efetivamente para cada uma das ações que temos.
    for (int m = 0; m < m_metricas; m++) {
        if (nomes_metricas[m] == "RET") {
            for (int i = 0; i < num_acoes; i++) {
                ids_temp[i] = i;
                if (acoes[i] == nullptr) {
                    valores_temp[i] = 0.0;
                } else {
                    valores_temp[i] = acoes[i]->getRET();
                }
            }
        } 
        else if (nomes_metricas[m] == "AVGRET") {
            for (int i = 0; i < num_acoes; i++) {
                ids_temp[i] = i;
                if (acoes[i] == nullptr) {
                    valores_temp[i] = 0.0;
                } else {
                    valores_temp[i] = acoes[i]->getAVGRET();
                }
            }
        } 
        else if (nomes_metricas[m] == "STAB") {
            for (int i = 0; i < num_acoes; i++) {
                ids_temp[i] = i;
                if (acoes[i] == nullptr) {
                    valores_temp[i] = 0.0;
                } else {
                    valores_temp[i] = acoes[i]->getSTAB();
                }
            }
        } 
        else if (nomes_metricas[m] == "CONS") {
            for (int i = 0; i < num_acoes; i++) {
                ids_temp[i] = i;
                if (acoes[i] == nullptr) {
                    valores_temp[i] = 0.0;
                } else {
                    valores_temp[i] = acoes[i]->getCONS();
                }
            }
        }
        if (num_acoes > 0) {
            quickSort(valores_temp, ids_temp, 0, num_acoes - 1);
        }
        
        for (int i = 0; i < num_acoes; i++) {
            int id_da_acao = ids_temp[i];
            double pontos_ganhos = (num_acoes - i); 
            pontuacao_final[id_da_acao] += pontos_ganhos * pesos[m];
        }
    }
    
    delete[] ids_temp;
    delete[] valores_temp;
    
    if (id_cliente < capacidade_clientes && clientes[id_cliente] != nullptr) {        
        int total_cliente = 0;
        noAcoes* temp = clientes[id_cliente]->getCarteira();
        
        while (temp != nullptr) {
            total_cliente++;
            temp = temp->proximo_no;
        }

        if (total_cliente > 0) {
            int* ids_cliente = new int[total_cliente];
            double* scores_cliente = new double[total_cliente];
            temp = clientes[id_cliente]->getCarteira();

            for (int i = 0; i < total_cliente; i++) {
                ids_cliente[i] = temp->id_acao;
                if (temp->id_acao < num_acoes) {
                    scores_cliente[i] = pontuacao_final[temp->id_acao];
                } else {
                    scores_cliente[i] = 0.0;
                }
                temp = temp->proximo_no;
            }

            quickSort(scores_cliente, ids_cliente, 0, total_cliente - 1);

            std::cout << std::fixed << std::setprecision(2);
            int qtd_m;
            if (n_retorno < total_cliente) {
                qtd_m = n_retorno;
            } else {
                qtd_m = total_cliente;
            }
            
            for (int i = 0; i < qtd_m; i++) {
                std::cout << "R " << id_consulta << " M " << i << " " << ids_cliente[i] << " " << scores_cliente[i] << std::endl;
            }

            int qtd_p = (n_retorno < total_cliente) ? n_retorno : total_cliente;
            for (int i = 0; i < qtd_p; i++) {
                int idx = total_cliente - 1 - i;
                std::cout << "R " << id_consulta << " P " << i << " " << ids_cliente[idx] << " " << scores_cliente[idx] << std::endl;
            }

            delete[] ids_cliente;
            delete[] scores_cliente;
        }
    }

    delete[] pontuacao_final;
}