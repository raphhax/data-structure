#ifndef STOCK_HPP
#define STOCK_HPP

class Stock {
private:
    int id;
    double* cotacao;
    int w;
    int quant_precos;

public:
    Stock(int id, int w);
    ~Stock();

    void addCotacao(double preco);

    int getId();
    double getRET();
    double getAVGRET();
    double getSTAB();
    double getCONS();
};

#endif