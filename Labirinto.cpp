#include <string.h>
#include <string>
#include <bits/stdc++.h> 

#include "Labirinto.h"
#include "PilhaArray.h"
#include "Gravador.h"
#include "Clock.h"

using namespace std;

Labirinto::Labirinto(vector<string> labirinto) {
  this->dados = labirinto;
  this->tempoExec = new Clock();
  achaEntrada();
}

void Labirinto::achaEntrada() {

  bool achou = false;

  for(int row = 0; row < dados.size(); row++) {
    for(int column = 0; column < dados[0].length(); column++) {
      if(dados[row][column] == 'E') {
        linhaAtual = row;
        colunaAtual = column;
        achou = true;
        break;
      }
    }
    if(achou) break;
  }

  if(achou) avancar();
  else cout<< "Labirinto não possue entrada!!!";
}

void Labirinto::avancar(){

  bool stop = false;

  while(!stop) { 
    int caminho = verificaCaminhos();

    if(caminho!=-8){
      ajustarPosicao(caminho);
      if(dados[linhaAtual][colunaAtual] == 'S') stop = true;
    } else {
      if(pilha->isVazia()) stop = true;
      else meiaVoltaVolver();
    }
  }

  if(pilha->isVazia()) cout << "Não foi possível encontrar uma saída!!!";
  else voltaAoInicio();
}

int Labirinto::verificaCaminhos() {
  
  char esquerda,emCima,direita,emBaixo;
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
    direcao = -8;
  }

  return direcao;
}

void Labirinto::ajustarPosicao(int caminho) {
  int empilha;
  switch(caminho){
    case 0:
      empilha = 0;
      pilha->empilha(empilha);
      dados[linhaAtual][colunaAtual] = '-';
      colunaAtual -= 1;
      break;
    case 1:
      empilha = 1;
      pilha->empilha(empilha);
      dados[linhaAtual][colunaAtual] = '-';
      linhaAtual -= 1;
      break;
    case 2:
      empilha = 2;
      pilha->empilha(empilha);
      dados[linhaAtual][colunaAtual] = '-';
      colunaAtual += 1;
      break;
    case 3:
      empilha = 3;
      pilha->empilha(empilha);
      dados[linhaAtual][colunaAtual] = '-';
      linhaAtual += 1;   
      break;
  }
}

void Labirinto::meiaVoltaVolver() {
  if(dados[linhaAtual][colunaAtual] == ' '){
    dados[linhaAtual][colunaAtual] = '-';
  }

  int anterior = pilha->desempilha();

  switch(anterior){
  case 0:
        colunaAtual += 1;
        break;
  case 1:
        linhaAtual += 1;
        break;
  case 2:
        colunaAtual -= 1;
        break;
  case 3:
        linhaAtual -= 1;
        break;
  }
}

void Labirinto::voltaAoInicio() {
 
  while(!pilha->isVazia()){
    meiaVoltaVolver();
    dados[linhaAtual][colunaAtual] = '*';
  }

  cout << "Tempo de Execução: ";
  cout << tempoExec->end();
  cout << " ms";

  Gravador *gravador = new Gravador();
  gravador->imprimirLabirinto(dados);
}