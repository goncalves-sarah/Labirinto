#include "PilhaArray.h"
#include <string.h>
#include <string>
using namespace std;

PilhaArray::PilhaArray(int capacidade) {
    this->capacidade = capacidade;
    this->dados = new string[capacidade];
    this->topo = -1;
}

void PilhaArray::limpar() {
    topo = -1;
}

void PilhaArray::empilha(string dado) {
    if (topo == capacidade-1) {
        int novaCapacidade = capacidade + 50;
        redimensionar(novaCapacidade);
    }
    topo = topo + 1;
    dados[topo] = dado;
}

string PilhaArray::desempilha()
{
    string dado = dados[topo];
    topo = topo -1;
    return dado;
}
bool PilhaArray::isVazia() const
{
    return topo == -1;
}

bool PilhaArray::isCheia() const
{
    return false;
}

PilhaArray::~PilhaArray()
{
    delete [] dados;
}

void PilhaArray::ajustarAoTamanho() {
    if (capacidade == topo+1) return;
    redimensionar(topo+1);
}

void PilhaArray::redimensionar(int novaCapacidade) {
    string *novo = new string[novaCapacidade];
    memcpy(novo, dados, capacidade*sizeof(string));
    delete [] dados;

    dados = novo;
    capacidade = novaCapacidade;
}
