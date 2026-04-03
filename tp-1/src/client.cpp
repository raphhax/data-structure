#include "client.hpp"
#include <iostream>

Client::Client(int id){
    this->id = id;
}

Client::~Client(){
    delete[] carteira;
}

