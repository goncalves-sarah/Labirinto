#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

#include "Leitor.h"
#include "PilhaArray.h"
#include "Gravador.h"

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
 
  PilhaArray pilha(150);
  
  for(int row = 0; row < linhas; row++) {
    for(int column = 0; column < colunas; column++) {
      if(dados[row][column] == 'E') {
        linhaAtual = row;
        colunaAtual = column;
        string empilha = to_string(linhaAtual) + to_string(colunaAtual);
        empilha += '3';
        pilha.empilha(empilha);
      }
      if(dados[row][column] == 'S'){
        linhaFinal = row;
        colunaFinal = column;
      }
    }
  }

  char esquerda,emCima,direita,emBaixo;
  bool saiu = false;
  int i = 0;

  while(!saiu) { 
      string empilha = to_string(linhaAtual) + to_string(colunaAtual);
      int direcao;
      esquerda = dados[linhaAtual][colunaAtual - 1];
      emCima = dados[linhaAtual - 1][colunaAtual];
      direita = dados[linhaAtual][colunaAtual + 1];
      emBaixo = dados[linhaAtual + 1][colunaAtual];


      if(esquerda == ' ' || esquerda == 'S' ) { //esquerda
        direcao = 0;
      } else if(emCima == ' '  || emCima == 'S' ) { //em cima
        direcao = 1;        
      } else if(direita == ' '  || direita == 'S' ) { // direita
        direcao = 2;        
      } else if(emBaixo == ' '  || emBaixo == 'S' ) { // emBaixo
        direcao = 3;        
      } else {
        dados[linhaAtual][colunaAtual] = '-';
        string anterior = pilha.desempilha();
        int size = anterior.length();
        direcao = '8';
      
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

      if(dados[linhaAtual][colunaAtual] == 'S'){
        saiu = true;
        while(!pilha.isVazia()){
          dados[linhaAtual][colunaAtual] = '*';
          string anterior = pilha.desempilha();
          int size = anterior.length();
                
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
      }
      i++;
  }
  
  for(int i = 0; i < dados.size();i++){
      cout << dados[i] << endl;
  }

  //Escrevendo Dados
  
  Gravador *gravador = new Gravador();
  
  gravador->imprimirLabirinto(dados);

  return 0;

}
