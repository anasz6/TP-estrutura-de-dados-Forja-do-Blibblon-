#include <cstdio>
#include "fila.h"

#define CHECA(cond) do { if (!(cond)) { printf("FALHOU linha %d: %s\n", __LINE__, #cond); return 1; } } while (0)

int main() {
    Fila f;
    Encomenda e;
    e.aventureiro = -1;
    e.item = -1;
 
//fila vazia
CHECA(f.vazia());
CHECA(!f.desenfileira(e));
CHECA(f.tamanho()==0);
CHECA(e.aventureiro==-1 && e.item == -1);

//posiçoes
Encomenda a{0,10};
Encomenda b{1,11};
Encomenda c = {2, 12};
CHECA(f.enfileira(a)==1);
CHECA(f.enfileira(b)==2);
CHECA(!f.vazia());
CHECA(f.tamanho()==2);

//Lógica FIFO
CHECA(f.desenfileira(e)  && e.aventureiro==0 && e.item==10);
CHECA(f.tamanho()==1);
CHECA(f.desenfileira(e) && e.aventureiro==1 && e.item==11);
CHECA(f.vazia());
CHECA(f.tamanho()==0);
CHECA(!f.desenfileira(e));

// enfileirar de novo depois de esvaziar (testa se o fim foi zerado)
  CHECA(f.enfileira(a) == 1);
  CHECA(f.desenfileira(e) && e.aventureiro == 0 && e.item == 10);
  CHECA(f.vazia());

  // intercalar: enfileira, desenfileira, enfileira...
  f.enfileira(a);
  f.enfileira(b);
  CHECA(f.desenfileira(e) && e.item == 10);
  CHECA(f.enfileira(c) == 2);
  CHECA(f.desenfileira(e) && e.item == 11);
  CHECA(f.desenfileira(e) && e.item == 12);
  CHECA(f.vazia());

  // volume
  for (int i = 0; i < 10000; i++) {
    Encomenda x = {i, i * 2};
    CHECA(f.enfileira(x) == i + 1);
  }
  CHECA(f.tamanho() == 10000);
  for (int i = 0; i < 10000; i++) {
    CHECA(f.desenfileira(e) && e.aventureiro == i && e.item == i * 2);
  }
  CHECA(f.vazia());

  // deixa nos na fila para o destrutor liberar (o valgrind confere)
  f.enfileira(a);
  f.enfileira(b);
  f.enfileira(c);

  printf("OK: teste_fila\n");
  return 0;
}
