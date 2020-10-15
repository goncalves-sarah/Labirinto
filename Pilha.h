#ifndef ED05_PILHA_H
#define ED05_PILHA_H

#include <string>
using namespace std;

class Pilha {
    public:
        virtual void limpar() = 0;
        virtual void empilha(string dado) = 0;
        virtual string desempilha() = 0;
        virtual bool isVazia() const = 0;
        virtual bool isCheia() const = 0;
        virtual ~Pilha() {}
};

#endif //ED05_PILHA_H
