#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

#include "Leitor.h"
#include "PilhaArray.h"

using namespace std;

int main() {
  
  int linhas, colunas;
  
  //Lendo os Dados
  Leitor *leitor = new Leitor();
  vector<string> dados = leitor->lerLabirinto("labirinto.txt");
  
  linhas = dados.size();
  colunas = dados[0].length();

  //Resolvendo o Labirinto
  int linhaAtual, colunaAtual, linhaFinal, colunaFinal;
 
  PilhaArray pilha(80);
  
  for(int row = 0; row < linhas; row++) {
    for(int column = 0; column < colunas; column++) {
      if(dados[row][column] == 'E') {
        dados[row][column] = '-';
        linhaAtual = row;
        colunaAtual = column;
      }
      if(dados[row][column] == 'S'){
        linhaFinal = row;
        colunaFinal = column;
      }
    }
  }

  int i = 0;

  while(linhaAtual!= linhaFinal && colunaAtual!= colunaFinal) { 
      string empilha = to_string(linhaAtual) + to_string(colunaAtual);
      int direcao;
    
      if(dados[linhaAtual][colunaAtual - 1] == ' ' || dados[linhaAtual][colunaAtual - 1] == 'S' ) { //esquerda
        direcao = 0;
      } else if(dados[linhaAtual - 1][colunaAtual] == ' '  || dados[linhaAtual - 1][colunaAtual] == 'S' )) { //em cima
        direcao = 1;        
      } else if(dados[linhaAtual][colunaAtual + 1] == ' '  || dados[linhaAtual][colunaAtual + 1] == 'S' )) { // direita
        direcao = 2;        
      } else if(dados[linhaAtual + 1][colunaAtual] == ' '  || dados[linhaAtual + 1][colunaAtual] == 'S' )) { // emBaixo
        direcao = 3;        
      } else {
        dados[linhaAtual][colunaAtual] = '-';
        string anterior = pilha.desempilha();
        int size = anterior.length();
        direcao = '8';
        cout << anterior[size-1] << endl;
        switch(anterior[size-1]){
        case '0':
              colunaAtual += 1;
              break;
        case '1':
              linhaAtual += 1;
              break;
        case '2':
              colunaAtual -= 1;
              break;
        case '3':
              linhaAtual -= 1;
              break;
          } 
      }

       switch(direcao){
        case 0:
          empilha += '0';
          pilha.empilha(empilha);
          dados[linhaAtual][colunaAtual] = '-';
          colunaAtual -= 1;
          break;
        case 1:
          empilha += '1';
          pilha.empilha(empilha);
          dados[linhaAtual][colunaAtual] = '-';
          linhaAtual -= 1;
          break;
        case 2:
          empilha += '2';
          pilha.empilha(empilha);
          dados[linhaAtual][colunaAtual] = '-';
          colunaAtual += 1;
          break;
        case 3:
          empilha += '3';
          pilha.empilha(empilha);
          dados[linhaAtual][colunaAtual] = '-';
          linhaAtual += 1;   
          break;
      }
      i++;
  }
  
  for(int i = 0; i < dados.size();i++){
      cout << dados[i] << endl;
  }
  return 0;

}
