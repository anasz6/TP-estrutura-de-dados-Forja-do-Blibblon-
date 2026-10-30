#include "catalogo.h"

void Catalogo::zeraContadores(){
        matrizL.zeraContadores();
        matrizT.zeraContadores();
}

int Catalogo::getNumItens() const{
    return numItens;
}

int Catalogo::getNumAtributos() const{
    return numAtributos;
}

Modo Catalogo::getModo() const{
     return modoAtual;
}

Catalogo::Catalogo(){
   modoAtual = MODO_T;
   numItens=0;
   numAtributos=0;
}

void Catalogo::cresceItens(int n){
        matrizL.cresceItens(n);
        numItens = n;
}

void Catalogo::cresceAtributos(int n){
    matrizL.cresceAtributos(n);
    numAtributos = n;
}

long long Catalogo::getvalor(int i, int a){
    if(modoAtual==MODO_L){
        long long val = matrizL.getvalor(i,a);
        return val;
    } else {
       long long val = matrizT.getvalor(i,a);
       return val;
    }
}

void Catalogo::set(int i, int a, long long v){
    if(modoAtual == MODO_L){
        matrizL.set(i,a,v);
    } else {
        matrizT.set(i,a,v);
    }
}

 void Catalogo::remove(int i, int a){
    if(modoAtual==MODO_L){
        matrizL.remove(i,a);
    } else {
        matrizT.remove(i,a);
    }
 }

Cursor Catalogo::iniciaLinha(int i){
   Cursor c;
    if(modoAtual==MODO_L){
   c = matrizL.iniciaLinha(i);
 } else {
   c = matrizT.iniciaLinha(i);
 }
 return c;
}

bool Catalogo::andaLinha(Cursor& c, Celula& saida){
    bool result;
    if(modoAtual==MODO_L){
         result = matrizL.andaLinha(c,saida);
    } else {
        result = matrizT.andaLinha(c,saida);
    }
    return result;
}

Cursor Catalogo::iniciaColuna(int a){
   Cursor c;
    if(modoAtual==MODO_L){
        c = matrizL.iniciaColuna(a);
    } else {
        c = matrizT.iniciaColuna(a);
    }
    return c;
}

bool Catalogo::andaColuna(Cursor& c, Celula& saida){
    bool result;
    if(modoAtual==MODO_L){
         result = matrizL.andaColuna(c,saida);
    } else {
        result = matrizT.andaColuna(c,saida);
    }
    return result;
}

long long Catalogo::produtoInternoLinhas(int i, int j){
    long long total;
    if(modoAtual == MODO_L){
        total = matrizL.produtoInternoLinhas(i,j);
    } else {
        total = matrizT.produtoInternoLinhas(i,j);
    }
    return total;
}

long long Catalogo::bytesUsados() const{
    long long total;
    if(modoAtual == MODO_L){
        total = matrizL.bytesUsados();
    } else {
        total = matrizT.bytesUsados();
    }
    return total;
}

void Catalogo::trocaModo(Modo novo){
  if(novo == modoAtual){
    return;
  }
  if(novo == MODO_L){
    matrizL.limpa();
    matrizL.cresceAtributos(numAtributos);
    matrizL.cresceItens(numItens);
    matrizL.iniciaConstrucao();
    for(int p = 0; p < matrizT.numCelulas(); p++){
        Celula auxiliar = matrizT.celulaEm(p);
        matrizL.anexaOrdenado(auxiliar.item, auxiliar.atributo, auxiliar.valor);
    }
    matrizL.finalizaConstrucao();
    matrizT.limpa();
  } else {
    matrizT.limpa();
    Cursor c;
    for(int p = 0; p < numItens; p++){
       c = matrizL.iniciaLinha(p);
       Celula saida;
       while(matrizL.andaLinha(c, saida)){
           matrizT.adicionaNoFim(saida);
       }
    }
    matrizL.limpa();
  }
  modoAtual= novo;
  zeraContadores();
}



