#include "fila.h"

int Fila::enfileira(const Encomenda& e){
    No* caixa = new No;
    caixa->dado = e;
    caixa->prox = nullptr;
    if(inicio==nullptr){
        inicio = caixa;
        fim = caixa;

    } else {
        fim->prox = caixa;
        fim =caixa;
    }
    tam++;
    return tam;
}

bool Fila::desenfileira(Encomenda& saida){
    
    if(inicio==nullptr){
        return false;
    } else {
    No* lixo = inicio;
    saida = inicio->dado;
    inicio = inicio->prox;
    if(tam ==1){
            fim = nullptr;
        }
    tam--;
    delete lixo;
    return true;
    }
        
}

bool Fila::vazia() const{
    if(inicio == nullptr){
        return true;
    } else {
        return false;
    }
}

int Fila::tamanho() const{
     return tam;
}

 Fila::Fila(){
    inicio = nullptr;
    fim = nullptr;
    tam=0;
 }

 Fila::~Fila(){
   Encomenda e;
   while( desenfileira(e));
 }