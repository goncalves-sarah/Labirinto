#ifndef ED05_CLOCK_H
#define ED05_CLOCK_H

#include <string>
#include <bits/stdc++.h> 
#include <time.h>  

using namespace std;

class Clock {
private: 
  clock_t tempo;

public:

    explicit Clock();

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    Clock(const Clock& other) = delete;
    Clock& operator = (const Clock& other) = delete;
    
    double end();

    ~Clock();
};


#endif //ED05_CLOCK_H
