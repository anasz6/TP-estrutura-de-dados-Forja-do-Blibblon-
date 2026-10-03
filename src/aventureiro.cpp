#include "aventureiro.h"

Aventureiro::Aventureiro(int id, const std::string& nome){
        id_ = id;
        nome_=nome;
}

int Aventureiro::getid() const{
    return id_;
}

const std::string& Aventureiro::getnome() const{
    return nome_;
}

void Aventureiro::equipa(int item){
build_.empilha(item);
}

bool Aventureiro::desequipa(int& item){
    bool x = build_.vazia();
    if(x){
        return false;
    } else {
     build_.desempilha(item);
     return true;
    }
}

int Aventureiro::numEquipados() const{
   return build_.tamanho();
}

int Aventureiro::itemEquipado(int k) const{
    return build_.elemento(k);
}