#include "PilhaArray.h"
#include <string.h>
#include <string>
using namespace std;

PilhaArray::PilhaArray(int capacidade) {
    this->capacidade = capacidade;
    this->dados = new int[capacidade];
    this->topo = -1;
}

void PilhaArray::limpar() {
    topo = -1;
}

void PilhaArray::empilha(int dado) {
    if (topo == capacidade-1) {
        int novaCapacidade = capacidade + 10;
        redimensionar(novaCapacidade);
    }
    topo = topo + 1;
    dados[topo] = dado;
}

int PilhaArray::desempilha()
{
    int dado = dados[topo];
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
    int *novo = new int[novaCapacidade];
    memcpy(novo, dados, capacidade*sizeof(int));
    delete [] dados;

    dados = novo;
    capacidade = novaCapacidade;
}
