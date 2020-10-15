#include <iostream>
#include <string>
#include <bits/stdc++.h> 

#include "Leitor.h"
#include "Labirinto.h"

using namespace std;

int main() {
  
  //Lendo os Dados
  Leitor *leitor = new Leitor();
  vector<string> dados = leitor->lerLabirinto("labirinto.txt");

  Labirinto *labirinto = new Labirinto(dados);

  return 0;

}
