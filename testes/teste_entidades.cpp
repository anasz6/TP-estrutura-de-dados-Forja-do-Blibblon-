#include "aventureiro.h"
#include "atributo.h"
#include "item.h"
#include <cstdio>

#define CHECA(cond) do { if (!(cond)) { printf("FALHOU linha %d: %s\n", __LINE__, #cond); return 1; } } while (0)

int main(){

//teste atriuicoes
Atributo a(0,"faca");
CHECA(a.getid() == 0);
CHECA(a.getnome()=="faca");
Atributo b(1,"faca");
CHECA(b.getid()==1);
CHECA(b.getnome()=="faca");

//teste itens
Item d(0,"faca");
CHECA(d.getid() == 0);
CHECA(d.getnome()=="faca");
Item e(1,"faca");
CHECA(e.getid()==1);
CHECA(e.getnome()=="faca");

int i = 1;
Aventureiro c(3,"Tommy");
CHECA(c.numEquipados()==0);
CHECA(!c.desequipa(i)&& i==1);
c.equipa(5);
c.equipa(9);
CHECA(c.numEquipados()==2);
CHECA(c.itemEquipado(0)==5 && c.itemEquipado(1)==9);

//teste desequipar
CHECA(c.desequipa(i) && i == 9);
CHECA(c.desequipa(i) && i==5);
CHECA(c.numEquipados() == 0);

//teste de equipar mesmo item
c.equipa(7);
c.equipa(7);
CHECA(c.itemEquipado(0)==7 && c.itemEquipado(1)==7);
CHECA(c.numEquipados()==2);

printf("OK: teste_entidades\n");
return 0;

}