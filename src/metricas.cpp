#include "metricas.h"
#include <cmath>

static long long arredonda6(double val) {
  return static_cast<long long>(std::round(val * 1e6));
}

void calculaPoder(Catalogo& cat, int N, long long* chave) {
  for (int i = 0; i < N; i++) {
    Cursor c = cat.iniciaLinha(i);
    Celula cell;
    double soma = 0.0;
    while (cat.andaLinha(c, cell)) {
      soma += cell.valor;
    }
    chave[i] = arredonda6(soma);
  }
}

void calculaEquilibrio(Catalogo& cat, int N, int T, long long* chave) {
  if (T <= 0) {
    for (int i = 0; i < N; i++) {
      chave[i] = arredonda6(1.0);
    }
    return;
  }

  for (int i = 0; i < N; i++) {
    Cursor c = cat.iniciaLinha(i);
    Celula cell;
    long long soma = 0;
    long long somaQuadrados = 0;

    while (cat.andaLinha(c, cell)) {
      soma += cell.valor;
      somaQuadrados += cell.valor * cell.valor;
    }

    // Var = (1/T) * sum (v_i - mu)^2 = ( T * sum(v^2) - (sum v)^2 ) / T^2
    // sigma = sqrt( T * sum(v^2) - (sum v)^2 ) / T
    long long termo = static_cast<long long>(T) * somaQuadrados - (soma * soma);
    if (termo < 0) termo = 0;
    double sigma = std::sqrt(static_cast<double>(termo)) / T;
    double eq = 1.0 / (1.0 + sigma);

    chave[i] = arredonda6(eq);
  }
}

void calculaSinergia(Catalogo& cat, int N, int T, const long long* build, long long* chave) {
  (void)T;

  double normaBuildSq = 0.0;
  if (build != nullptr) {
    for (int a = 0; a < T; a++) {
      normaBuildSq += static_cast<double>(build[a]) * static_cast<double>(build[a]);
    }
  }

  double normaBuild = std::sqrt(normaBuildSq);

  for (int i = 0; i < N; i++) {
    Cursor c = cat.iniciaLinha(i);
    Celula cell;
    double dot = 0.0;
    double normaItemSq = 0.0;

    while (cat.andaLinha(c, cell)) {
      normaItemSq += static_cast<double>(cell.valor) * static_cast<double>(cell.valor);
      if (build != nullptr && cell.atributo >= 0 && cell.atributo < T) {
        dot += static_cast<double>(cell.valor) * static_cast<double>(build[cell.atributo]);
      }
    }

    double normaItem = std::sqrt(normaItemSq);

    if (normaItem == 0.0 || normaBuild == 0.0) {
      chave[i] = 0;
    } else {
      double sinergia = dot / (normaItem * normaBuild);
      chave[i] = arredonda6(sinergia);
    }
  }
}

