#include <fstream>
#include <string>
#include <bits/stdc++.h> 

#include "Gravador.h"

using namespace std;

Gravador::Gravador() {}

void Gravador::imprimirLabirinto(vector<string> labirinto) {
  ofstream myfile ("labirintoResposta.txt"); 
  for(int linha = 0; linha < labirinto.size();linha++) {
    myfile << labirinto[linha] + "\n";
  }
  myfile.close();
}

Gravador::~Gravador(){}



