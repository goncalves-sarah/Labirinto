#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

#include "Leitor.h"

using namespace std;

int main() {
  
  int linhas, colunas;
  
  //Lendo os Dados
  Leitor *leitor = new Leitor();
  vector<string> dados = leitor->lerLabirinto("labirinto.txt");
  
  linhas = dados.size();
  colunas = dados[0].length();

  //Resolvendo o Labirinto
  int posicao[2];
  
  for(int row = 0; row < linhas; row++) {
    for(int column = 0; column < colunas; column++) {
      if(dados[row][column] == 'E') {
        cout << "entrou" << endl;
        posicao[0] = row;
        posicao[1] = column;
      }
    }
  }

  return 0;

}
