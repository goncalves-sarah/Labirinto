#include "Pilha.h"
#include <string>
using namespace std;

#ifndef ED05_PILHAARRAY_H
#define ED05_PILHAARRAY_H

class PilhaArray : public Pilha {
private:
    string *dados;
    int capacidade;
    int topo;
    double fator;

    void redimensionar(int novaCapacidade);

public:
    explicit PilhaArray(int capacidade);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    PilhaArray(const PilhaArray& other) = delete;
    PilhaArray& operator = (const PilhaArray& other) = delete;

    virtual void limpar() override;
    virtual void empilha(string dado) override;
    virtual string desempilha() override;
    virtual bool isVazia() const override;
    virtual bool isCheia() const override;

    void ajustarAoTamanho();

    virtual ~PilhaArray();
};


#endif //ED05_PILHAARRAY_H
