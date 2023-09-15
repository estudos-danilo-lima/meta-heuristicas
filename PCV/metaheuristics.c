// Problema do Caixeiro Viajante (PCV)

// Nearest Neighbour Heristic (NNH)
// Algoritmo do vizinho mais proximo

#include "grafo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define POS_INICIAL 0
#define LIVRE 0
#define USO 1

void nnh(tGrafo g){
    int n = getN(g); // define o numero de vertices do grafo
    int ** ma = getMatrizAdjacencias(g); // define a matriz de distancias
    int custo = 0; // inicializa o custo da solucao
    int solution[n+1]; // vetor com as solucoes

    int options[n];  // vetor com as opcoes disponiveis
    for(int i = 0; i < n; i++){
        options[i] = LIVRE;
    }

    solution[0] = POS_INICIAL; // define um vertice como inicial da solucao
    solution[n] = POS_INICIAL; // adiciona o mesmo ao final da solucao para fechar o ciclo
    options[0] = USO; // remove o vertice das opções
    
    



    int origem = POS_INICIAL; // define a origem para ver qual proximo vertice destino
    for(int i = 1; i < n; i++){ // i representa qual casa da solucao estamos adicionando
        int dist = (int) INFINITY;  // dist é a menor distancia da origem aos demais
        int dest;                   // dest é o melhor destino
        for(int j = 0; j < n; j++){ 
            if(origem != j && options[j] == LIVRE){ // verifica se o vertice destino é valido
                if(ma[origem][j] <= dist){ // verifica se a distancia é melhor ate o momento
                    dist = ma[origem][j]; // atualiza a menor distancia
                    dest = j;             // atualiza o melhor destino
                }
            }
        }
        solution[i] = dest; // adiciona o destino na solucao 
        options[dest] = USO; // remove o destino da lista de opcoes
        origem = dest; // transforma o destino na nova origem
        custo += dist; // calcula o custo da solucao
    }

    custo += ma[solution[n-1]][POS_INICIAL]; // adiciona o custo de retornar ao ponto inicial


    printf("\nNNH solution: (%d", solution[0]+1);
    for(int i = 1; i <= n; i++){
        printf(", %d", solution[i]+1);
    }
    printf(") cost (%d)\n", custo);
}