#ifndef CELULA_H
#define CELULA_H

struct Celula {           
  int item;
  int atributo;
  long long valor;
};

struct Cursor {            
  int idx;                
  int fim;                
  int chave;              
  const void* no;          
};

#endif
