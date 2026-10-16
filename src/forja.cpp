#include "forja.h"

#include <cstdlib>   // strtoll
#include <cstdio>    // printf
#include <cstring>   // strcmp

static char* proximoToken(char*& p) {
  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
    p++;                                   // 1) pula os separadores do começo
  }
  if (*p == '\0') {
    return nullptr;                        // a linha acabou sem palavra
  }
  char* inicio = p;                        // 2) guarda onde a palavra começa
  while (*p != '\0' && *p != ' ' && *p != '\t' && *p != '\r' && *p != '\n') {
    p++;                                   // 3) anda até o fim da palavra
  }
  if (*p != '\0') {
    *p = '\0';                             // 4) fecha a palavra com '\0'
    p++;                                   // 5) avança para depois dela
  }
  return inicio;
}

static long long lerInteiro(char*& p) {
  char* t = proximoToken(p);
  if (t == nullptr) return 0;
  return strtoll(t, nullptr, 10);          // entende o sinal negativo
}

Forja::Forja() {
  algoritmo = ALG_INSERTION;
}

Forja::~Forja() {
  for (int i = 0; i < itens.tamanho(); i++) {
    delete itens[i];
  }
  for (int i = 0; i < atributos.tamanho(); i++) {
    delete atributos[i];
  }
  for (int i = 0; i < aventureiros.tamanho(); i++) {
    delete aventureiros[i];
  }
}

void Forja::setAlgoritmo(Algoritmo a) {
  algoritmo = a;
}

void Forja::executa(char* linha) {
  char* p = linha;
  char* cmd = proximoToken(p);
  if (cmd == nullptr) return;

  if (strcmp(cmd, "E") == 0) {
    cmdE(p);
  } else if (strcmp(cmd, "A") == 0) {
    cmdA(p);
  } else if (strcmp(cmd, "I") == 0) {
    cmdI(p);
  } else if (strcmp(cmd, "H") == 0) {
    cmdH(p);
  } else if (strcmp(cmd, "M") == 0) {
    cmdM(p);
  } else if (strcmp(cmd, "LI") == 0) {
    cmdLI(p);
  } else if (strcmp(cmd, "LA") == 0) {
    cmdLA(p);
  } else if (strcmp(cmd, "F") == 0) {
    cmdF(p);
  } else if (strcmp(cmd, "Z") == 0) {
    cmdZ(p);
  } else if (strcmp(cmd, "D") == 0) {
    cmdD(p);
  } else if (strcmp(cmd, "LH") == 0) {
    cmdLH(p);
  } else if (strcmp(cmd, "Q") == 0) {
    cmdQ(p);
  }
}

void Forja::cmdE(char* resto) {
  char* token = proximoToken(resto);
  Modo auxiliar; 
  if (token != nullptr && token[0] == 'L') {
    auxiliar = MODO_L;
    printf("E L\n");
  } else {
    auxiliar = MODO_T;
    printf("E T\n");
  }
  catalogo.trocaModo(auxiliar);
}

void Forja::cmdA(char* resto) {
  char* a = proximoToken(resto);
  int id = atributos.tamanho();
  Atributo* novo = new Atributo(id, a);
  atributos.adiciona(novo);
  catalogo.cresceAtributos(id + 1);
  printf("A %d\n", id);
}

void Forja::cmdI(char* resto) {
  char* aux = proximoToken(resto);
  int id = itens.tamanho();
  Item* novo = new Item(id, aux);
  catalogo.cresceItens(id + 1);
  itens.adiciona(novo);
  printf("I %d\n", id);
}

void Forja::cmdH(char* resto) {
  char* aux = proximoToken(resto);
  int id = aventureiros.tamanho();
  Aventureiro* novo = new Aventureiro(id, aux);
  aventureiros.adiciona(novo);
  printf("H %d\n", id);
}

void Forja::cmdM(char* resto) {
  int a = lerInteiro(resto); 
  int b = lerInteiro(resto);
  long long c = lerInteiro(resto);
  
  catalogo.set(a, b, c);

  std::string nomeI = itens[a]->getnome();
  std::string nomeA = atributos[b]->getnome();
  printf("M %s %s %lld\n", nomeI.c_str(), nomeA.c_str(), c);
}

void Forja::cmdLI(char* resto) {
  int id = lerInteiro(resto);
  std::string nomeI = itens[id]->getnome();
  printf("LI %s", nomeI.c_str());

  Cursor c = catalogo.iniciaLinha(id);
  Celula saida;
  int contador = 1;
  while (catalogo.andaLinha(c, saida)) {
    printf(" atributo_%d %d %lld", contador, saida.atributo, saida.valor);
    contador++;
  }
  if (contador == 1) {
    printf(" VAZIO");
  }
  printf("\n");
}

void Forja::cmdLA(char* resto) {
  int id = lerInteiro(resto);
  std::string nomeA = atributos[id]->getnome();
  printf("LA %s", nomeA.c_str());

  Cursor c = catalogo.iniciaColuna(id);
  Celula saida;
  int contador = 1;
  while (catalogo.andaColuna(c, saida)) {
    printf(" item_%d %d %lld", contador, saida.item, saida.valor);
    contador++;
  }
  if (contador == 1) {
    printf(" VAZIO");
  }
  printf("\n");
}

void Forja::cmdF(char* resto) {
  int av_id = lerInteiro(resto);
  int item_id = lerInteiro(resto);
  Encomenda enc{av_id, item_id};
  int tam = fila.enfileira(enc);
  printf("F %d\n", tam);
}

void Forja::cmdZ(char* resto) {
  int k = lerInteiro(resto);

  Encomenda enc;
  int cont = 1;
  VetorDinamico<Encomenda> processadas;
  while (k > 0 && fila.desenfileira(enc)) {
    if (enc.aventureiro >= 0 && enc.aventureiro < aventureiros.tamanho()) {
      aventureiros[enc.aventureiro]->equipa(enc.item);
    }
    processadas.adiciona(enc);
    k--;
  }

  printf("Z %d\n", processadas.tamanho());
  bool primeiro = true;
  for (int i = 0; i < processadas.tamanho(); i++) {
    if (!primeiro) {
      printf(" ");
    }
    printf("encomenda_%d %d %d", cont, processadas[i].aventureiro, processadas[i].item);
    primeiro = false;
    cont++;
  }
  printf("\n");
}

void Forja::cmdD(char* resto) {
  int av_id = lerInteiro(resto);
  int item_desequipado = -1;
  if (av_id >= 0 && av_id < aventureiros.tamanho()) {
    Aventureiro* av = aventureiros[av_id];
    if (av->desequipa(item_desequipado)) {
      std::string nomeAv = av->getnome();
      std::string nomeItem = itens[item_desequipado]->getnome();
      printf("D %s %s\n", nomeAv.c_str(), nomeItem.c_str());
      return;
    }
  }
}

void Forja::calculaBuild(Aventureiro* av, VetorDinamico<long long>& build) {
  int numAtrib = atributos.tamanho();
  build.limpa();
  build.redimensiona(numAtrib, 0);

  if (av == nullptr) return;

  int nEquip = av->numEquipados();
  for (int e = 0; e < nEquip; e++) {
    int itemId = av->itemEquipado(e);
    Cursor c = catalogo.iniciaLinha(itemId);
    Celula cell;
    while (catalogo.andaLinha(c, cell)) {
      if (cell.atributo >= 0 && cell.atributo < numAtrib) {
        build[cell.atributo] += cell.valor;
      }
    }
  }
}

void Forja::cmdLH(char* resto) {
  int av_id = lerInteiro(resto);
  if (av_id < 0 || av_id >= aventureiros.tamanho()) return;

  Aventureiro* av = aventureiros[av_id];
  printf("LH %s", av->getnome().c_str());

  VetorDinamico<long long> build;
  calculaBuild(av, build);

  int contador = 1;
  for (int a = 0; a < build.tamanho(); a++) {
    if (build[a] != 0) {
      printf(" atributo_%d %d %lld", contador, a, build[a]);
      contador++;
    }
  }
  if (contador == 1) {
    printf(" VAZIO");
  }
  printf("\n");
}

void Forja::cmdQ(char* resto) {
  // Ignorado / corpo vazio (depende dos algoritmos de ordenação)
  (void)resto;
}
