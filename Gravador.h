#ifndef ED05_GRAVADOR_H
#define ED05_GRAVADOR_H

#include <string>
#include <bits/stdc++.h> 

using namespace std;

class Gravador {

public:
    explicit Gravador();

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    Gravador(const Gravador& other) = delete;
    Gravador& operator = (const Gravador& other) = delete;
    

    void imprimirLabirinto(vector<string> labirinto);
    ~Gravador();
};


#endif //ED05_GRAVADOR_H
