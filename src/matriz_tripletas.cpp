#include "matriz_tripletas.h"
#include "celula.h"

int MatrizTripletas::buscaPos(int i, int a, bool& achou) const {
    achou = false;
    int esq = 0;
    int dir = v_.tamanho();

    while (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        if (v_[meio].item < i || (v_[meio].item == i && v_[meio].atributo < a)) {
            esq = meio + 1;
        } else {
            dir = meio;
        }
    }

    if (esq < v_.tamanho() && v_[esq].item == i && v_[esq].atributo == a) {
        achou = true;
    }
    return esq;
}

int MatrizTripletas::primeiroComItemMaiorOuIgual(int i) const {
    int esq = 0;
    int dir = v_.tamanho();

    while (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        if (v_[meio].item < i) {
            esq = meio + 1;
        } else {
            dir = meio;
        }
    }
    return esq;
}

long long MatrizTripletas::getvalor(int i, int a){
    bool achou;   
    int pos = buscaPos(i,a,achou);
    if(achou){
        long long valor = v_[pos].valor;
        return valor;
    } else {
        return 0;
    }
}

 void MatrizTripletas::set(int i, int a, long long v){
      bool achou;
      int pos = buscaPos(i,a,achou);
      if (v == 0){
        remove(i,a);
      } else if(!achou){
        Celula nova {i,a,v};
        v_.insereEm(pos, nova);
      } else if (achou){
        v_[pos].valor = v;
      } 
 }

 void MatrizTripletas::remove(int i, int a){
    bool achou;  
    int pos = buscaPos(i,a,achou);
    if(achou){
    v_.removeEm(pos);
    }
 }

MatrizTripletas::MatrizTripletas() {
    percorridas = 0;
}

Cursor MatrizTripletas::iniciaLinha(int i){
    Cursor a;
    a.idx = primeiroComItemMaiorOuIgual(i);
    a.fim = primeiroComItemMaiorOuIgual(i+1);
    a.no = nullptr;
    return a;
}

bool MatrizTripletas::andaLinha(Cursor& c, Celula& saida){
        if(c.idx < c.fim){
         saida.item = v_[c.idx].item;
         saida.atributo= v_[c.idx].atributo;
         saida.valor = v_[c.idx].valor;
        c.idx = c.idx+1;
        percorridas++;
        return true;
        } else {
            return false;
        }
   }

Cursor MatrizTripletas::iniciaColuna(int a){
       Cursor c;
       c.chave = a;
       c.idx = 0;
       c.fim = v_.tamanho();
       c.no = nullptr;
       return c;
}
bool MatrizTripletas::andaColuna(Cursor& c, Celula& saida){    
    while (c.idx < c.fim) {
        percorridas++;
        if (v_[c.idx].atributo == c.chave) {
            saida.item = v_[c.idx].item;
            saida.atributo = v_[c.idx].atributo;
            saida.valor = v_[c.idx].valor;
            c.idx++;
            return true;
        }
        c.idx++;
    }
    return false;
}

long long MatrizTripletas::produtoInternoLinhas(int i, int j){
        Cursor ci = iniciaLinha(i);
        Cursor cj = iniciaLinha(j);
        Celula aj;
        Celula ai;
        bool primeiro = andaLinha(ci,ai);
        bool segundo = andaLinha(cj,aj);
        long long resultado = 0;

        while( primeiro && segundo){
            if(aj.atributo<ai.atributo){
                segundo = andaLinha(cj,aj);
            } else if (ai.atributo < aj.atributo){
                primeiro = andaLinha(ci,ai);
            } else if(aj.atributo == ai.atributo){
                resultado = resultado + (aj.valor*ai.valor);
                segundo = andaLinha(cj,aj);
                primeiro = andaLinha(ci,ai);
            }
        }
        return resultado;
}

void MatrizTripletas::limpa(){
    v_.limpa();
 }

void MatrizTripletas::adicionaNoFim(const Celula& c){
     v_.adiciona(c);
 }

int MatrizTripletas::numCelulas() const{
      return v_.tamanho();
 }

Celula MatrizTripletas::celulaEm(int pos) const{
       Celula a;
       a.item = v_[pos].item;
       a.atributo = v_[pos].atributo;
       a.valor = v_[pos].valor;
       return a;
}

long long MatrizTripletas::bytesUsados() const{
    return v_.bytesReservados();
}

long long MatrizTripletas::celulasPercorridas() const{
    return percorridas;
}

void MatrizTripletas::zeraContadores(){
     percorridas = 0;
}

