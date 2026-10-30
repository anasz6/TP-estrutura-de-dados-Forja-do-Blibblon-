#include "forja.h"
#include <cstdio>
#include <cstring>

int main(int argc, char* argv[]) {
  Forja forja;

  if (argc > 1) {
    if (strcmp(argv[1], "insertion") == 0 || strcmp(argv[1], "0") == 0) {
      forja.setAlgoritmo(ALG_INSERTION);
    } else if (strcmp(argv[1], "merge") == 0 || strcmp(argv[1], "1") == 0) {
      forja.setAlgoritmo(ALG_MERGE);
    } else if (strcmp(argv[1], "quick") == 0 || strcmp(argv[1], "2") == 0) {
      forja.setAlgoritmo(ALG_QUICK);
    }
  }

  char linha[4096];
  while (fgets(linha, sizeof(linha), stdin) != nullptr) {
    forja.executa(linha);
  }
  return 0;
}

