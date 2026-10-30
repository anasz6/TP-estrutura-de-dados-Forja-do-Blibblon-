#include "matriz_lista_cruzada.h"

int MatrizListaCruzada::numCelulas() const{
   return numNos;
}

long long MatrizListaCruzada::celulasPercorridas() const{
   return percorridas;
}

void MatrizListaCruzada::zeraContadores(){
   percorridas = 0;

}

long long MatrizListaCruzada::bytesUsados() const{
      long long total = 0;
      total = cabecaColuna.bytesReservados() + cabecaLinha.bytesReservados() + ((long long)numNos*sizeof(No));
      return total;
}

MatrizListaCruzada::MatrizListaCruzada(){
  numNos = 0;
  percorridas = 0;
}

void MatrizListaCruzada::cresceItens(int n){
   if(n > cabecaLinha.tamanho()){
    No* nada= nullptr;
    cabecaLinha.redimensiona(n,nada);
   } 
}

void MatrizListaCruzada::cresceAtributos(int n){
    if ( n > cabecaColuna.tamanho()){
        No* nada= nullptr;
    cabecaColuna.redimensiona(n,nada);
   }
}               
//FAZER depois
 void MatrizListaCruzada::limpa(){
     for (int i = 0; i < cabecaLinha.tamanho(); i++) {
        No* atual = cabecaLinha[i];
        while (atual != nullptr) {
            No* proximo = atual->proxLinha;
            delete atual;
            atual = proximo;
        }
        cabecaLinha[i] = nullptr;
    }
    // Zera as cabeças de coluna (os nós já foram deletados acima)
    for (int j = 0; j < cabecaColuna.tamanho(); j++) {
        cabecaColuna[j] = nullptr;
    }
    numNos = 0;
 }

 MatrizListaCruzada::~MatrizListaCruzada(){
   limpa();
 }

long long MatrizListaCruzada::getvalor(int i, int a){
    if(i>=cabecaLinha.tamanho()){
        return 0;
    }
     No* auxiliar = cabecaLinha[i];
    while(auxiliar != nullptr && auxiliar->atributo!= a){
       auxiliar = auxiliar->proxLinha;
     }
     if(auxiliar != nullptr && auxiliar->atributo==a){
     return auxiliar->valor;
     } else {
        return 0;
     }
 }
//não tem proteção contra indice fora do vetor;
  void MatrizListaCruzada::set(int i, int a, long long v){;
    if(v == 0){
        remove(i,a);
        return;
    } else {
        No* auxiliar = cabecaLinha[i];
        No* antAuxiliar = nullptr;
    
        //linha
        while(auxiliar != nullptr && a > auxiliar->atributo){
            antAuxiliar = auxiliar;
            auxiliar = auxiliar->proxLinha;
        }
        //verifica se a celula já existe
        if(auxiliar != nullptr && auxiliar->atributo == a){
            auxiliar->valor = v;
            return;
        }

        No* coisa = new No;
            coisa->item = i;
            coisa->atributo = a;
            coisa->valor = v;
            coisa->proxColuna = nullptr;
            coisa->proxLinha = nullptr;

        //coluna
        No* Cauxiliar = cabecaColuna[a];
        No*antC = nullptr;
        while(Cauxiliar != nullptr && Cauxiliar->item <i){
             antC = Cauxiliar;
             Cauxiliar = Cauxiliar->proxColuna;
        }

        if(antAuxiliar == nullptr){
            cabecaLinha[i] = coisa;
            coisa->proxLinha = auxiliar;
        } else {
        antAuxiliar->proxLinha = coisa;
        coisa->proxLinha = auxiliar;
        }
        if(antC == nullptr){
         cabecaColuna[a] = coisa;
         coisa->proxColuna = Cauxiliar;
        } else {
        coisa->proxColuna = Cauxiliar;
        antC->proxColuna = coisa;
        }
        numNos++;
        return;
    }
  }
//também sem proteção contra índice fora do vetor
  void MatrizListaCruzada::remove(int i, int a){
       No* auxiliar = cabecaLinha[i];
       No* antAuxiliar = nullptr;

       while(auxiliar != nullptr && auxiliar->atributo != a){
        antAuxiliar = auxiliar;
        auxiliar = auxiliar->proxLinha;
       }
       if(auxiliar == nullptr){
        return;
       }
       if  (antAuxiliar== nullptr){
        cabecaLinha[i] = auxiliar->proxLinha;
       }  else {
       antAuxiliar->proxLinha = auxiliar->proxLinha;
       }

       No* Cauxiliar = cabecaColuna[a];
       No* antC = nullptr;

       while(Cauxiliar!= nullptr &&  Cauxiliar != auxiliar){
            antC = Cauxiliar;
            Cauxiliar = Cauxiliar->proxColuna;
       }
       if(antC == nullptr){
        cabecaColuna[a] = Cauxiliar->proxColuna;
       } else {
       antC->proxColuna = Cauxiliar->proxColuna;
       }
       delete auxiliar;
       numNos--;

       return;
  }

  Cursor MatrizListaCruzada::iniciaLinha(int i){
     Cursor c;
      c.no = nullptr;
     if(i >= cabecaLinha.tamanho()){
        return c;
     } else if(cabecaLinha[i]!=nullptr){
     c.no = cabecaLinha[i];
     return c;
     }
     return c;
  }

bool MatrizListaCruzada::andaLinha(Cursor& c, Celula& saida){
     if(c.no == nullptr){
        return false;
     }
     const No* auxiliar = static_cast<const No*>(c.no);
     saida.item = auxiliar->item;
     saida.atributo = auxiliar->atributo;
     saida.valor = auxiliar->valor;
     auxiliar= auxiliar->proxLinha;
     c.no = auxiliar;
     percorridas++;
     return true;
}

Cursor MatrizListaCruzada::iniciaColuna(int a){
     Cursor c;
      c.no = nullptr;
     if(a >= cabecaColuna.tamanho()){
        return c;
     } else if(cabecaColuna[a]!=nullptr){
     c.no = cabecaColuna[a];
     return c;
     }
     return c;
}

bool MatrizListaCruzada::andaColuna(Cursor& c, Celula& saida){
   if(c.no == nullptr){
        return false;
     }
     const No* auxiliar = static_cast<const No*>(c.no);
     saida.item = auxiliar->item;
     saida.atributo = auxiliar->atributo;
     saida.valor = auxiliar->valor;
     auxiliar= auxiliar->proxColuna;
     c.no = auxiliar;
     percorridas++;
     return true;
}

long long MatrizListaCruzada::produtoInternoLinhas(int i, int j){
    No* auxiliar = cabecaLinha[i];
    No* Caux = cabecaLinha[j];
    long long total = 0;
  
   while(auxiliar != nullptr && Caux != nullptr){
       if(Caux->atributo > auxiliar->atributo){
           auxiliar = auxiliar->proxLinha;
        } else if( Caux->atributo< auxiliar->atributo){
              Caux = Caux->proxLinha;
        } else {
            total = total + (auxiliar->valor*Caux->valor);
            auxiliar = auxiliar->proxLinha;
            Caux = Caux->proxLinha;
        }
    }
    return total;
}


//para transferencia de um modo para o outro 
void MatrizListaCruzada::iniciaConstrucao(){
   ultimoColuna.limpa();
   ultimoLinha.limpa();
   No* nada = nullptr;
    for(int i = 0; i<cabecaColuna.tamanho();i++){
    ultimoColuna.adiciona(nada);
   }
   for(int j = 0; j<cabecaLinha.tamanho();j++){
    ultimoLinha.adiciona(nada);
   }
}
//mesma coisa do set, mas com atalho pois as celulas já chegam em ordem
void MatrizListaCruzada::anexaOrdenado(int i, int a, long long v){
 No* aux = new No;
 aux->item = i;
 aux->atributo = a;
 aux->valor = v;
 aux->proxColuna = nullptr;
 aux->proxLinha = nullptr;

 if(ultimoLinha[i]!= nullptr){
     ultimoLinha[i]->proxLinha = aux;
 } else if( ultimoLinha[i] == nullptr){
    cabecaLinha[i] = aux;
 } 
 if(ultimoColuna[a] != nullptr){
    ultimoColuna[a]->proxColuna = aux;
 }  else if(ultimoColuna[a] == nullptr){
    cabecaColuna[a]=aux;
 }
 numNos++;
 ultimoColuna[a] = aux;
 ultimoLinha[i] = aux;
}

void MatrizListaCruzada::finalizaConstrucao(){ 
    ultimoColuna.limpa();
    ultimoLinha.limpa();
}