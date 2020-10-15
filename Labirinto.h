#include <string>
#include <bits/stdc++.h> 

#include "PilhaArray.h"

using namespace std;

#ifndef ED05_LABIRINTO_H
#define ED05_LABIRINTO_H

class Labirinto {
private:
  int linhaAtual, colunaAtual;
  vector<string> dados;
  PilhaArray *pilha = new PilhaArray(150);

public:
    explicit Labirinto(vector<string> labirinto);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    Labirinto(const Labirinto& other) = delete;
    Labirinto& operator = (const Labirinto& other) = delete;

    void achaEntrada();
    int verificaCaminhos();
    void meiaVoltaVolver();
    void avancar();
    void ajustarPosicao(int caminho);
    void voltaAoInicio();

    ~Labirinto();
};

#endif //ED05_LABIRINTO_H
