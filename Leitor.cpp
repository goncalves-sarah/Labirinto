#include <fstream>
#include <string>
#include <bits/stdc++.h> 

#include "Leitor.h"

using namespace std;

Leitor::Leitor() {}

vector<string> Leitor::lerLabirinto(string nomeArquivo) {
  string line;
  vector<string> dados;
  ifstream myfile (nomeArquivo); 
  if (myfile.is_open()){
    while (! myfile.eof() ) {
      getline(myfile,line);
      dados.push_back(line);
    }
    myfile.close();
  } else cout << "Unable to open file";
  return dados;
}

Leitor::~Leitor(){}



