#include "pilha.h"

void Pilha::empilha(int item){
 itens_.adiciona(item);
};

bool Pilha::desempilha(int &item){
 
    if(itens_.tamanho()==0){
    return false; 
}  else {
    item=itens_[itens_.tamanho()-1];
     itens_.removeEm(itens_.tamanho()-1);
     return true;
}
};

bool Pilha::topo(int &item)const{
    if(itens_.tamanho()==0){
        return false;
    } else {
        item = itens_[itens_.tamanho()-1];
        return true;
    }
};

 bool Pilha::vazia() const{
    if(itens_.tamanho()==0){
        return true;
    } else{
        return false;
    }
 };

int Pilha::elemento(int k) const{
    return itens_[k];
};

int Pilha::tamanho() const{
   return itens_.tamanho();
}