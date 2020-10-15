#ifndef ED05_LEITOR_H
#define ED05_LEITOR_H

#include <string>
#include <bits/stdc++.h> 

using namespace std;

class Leitor {

public:
    explicit Leitor();

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    Leitor(const Leitor& other) = delete;
    Leitor& operator = (const Leitor& other) = delete;
    

    vector<string> lerLabirinto(string nomeArquivo);
    ~Leitor();
};


#endif //ED05_LEITOR_H
