#ifndef METRICAS_H
#define METRICAS_H

#include "catalogo.h"

// Cada função preenche chave[i], para i de 0 a N-1, com o valor da métrica do item i,
// já arredondado a 6 casas e multiplicado por 1e6 (um inteiro).
void calculaPoder(Catalogo& cat, int N, long long* chave);
void calculaEquilibrio(Catalogo& cat, int N, int T, long long* chave);
void calculaSinergia(Catalogo& cat, int N, int T, const long long* build, long long* chave);

#endif
