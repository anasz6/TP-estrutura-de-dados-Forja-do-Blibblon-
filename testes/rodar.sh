#!/bin/bash
# uso (na raiz do projeto): ./testes/rodar.sh
for f in testes/*.in; do
  esperado="${f%.in}.out"
  ./bin/tp1.out < "$f" > /tmp/saida.txt
  if diff -q /tmp/saida.txt "$esperado" > /dev/null; then
    echo "OK     $f"
  else
    echo "FALHOU $f   (veja: diff /tmp/saida.txt $esperado)"
  fi
done
