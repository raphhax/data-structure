#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

struct noAcoes{
    int id_acao;
    noAcoes* proximo_no;
};

class Client{

private:
    int id;
    noAcoes* carteira;

public:
    Client(int id);
    ~Client();

    void compra_acao(int id_acao);
    void vende_acao(int id_acao);
    noAcoes* getCarteira();
    int getId();
};


#endif