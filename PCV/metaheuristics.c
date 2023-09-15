// Problema do Caixeiro Viajante (PCV)
// Algoritmos Construtivos https://drive.google.com/file/d/1g1upO5FIZ7BTnwYGBjEm9LOetNSHKn4m/view
// Algoritmos de Busca Local https://drive.google.com/file/d/1aWgKoE3RIlQmPf7JAHQz_1zdKvcl88Iu/view
#include "metaheuristics.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
ALGORITMO CONSTRUTIVO
Nearest Neighbour Heristic (NNH)
Algoritmo do vizinho mais proximo
*/ 

void nnh(int ** md, int n){
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
                if(md[origem][j] <= dist){ // verifica se a distancia é melhor ate o momento
                    dist = md[origem][j]; // atualiza a menor distancia
                    dest = j;             // atualiza o melhor destino
                }
            }
        }
        solution[i] = dest; // adiciona o destino na solucao 
        options[dest] = USO; // remove o destino da lista de opcoes
        origem = dest; // transforma o destino na nova origem
        custo += dist; // calcula o custo da solucao
    }

    custo += md[solution[n-1]][POS_INICIAL]; // adiciona o custo de retornar ao ponto inicial


    printf("NNH solution: (%d", solution[0]+1);
    for(int i = 1; i <= n; i++){
        printf(", %d", solution[i]+1);
    }
    printf(") cost (%d)\n", custo);
}

void nnh_backtracking(int ** matriz_dist, int n){
    //imprlementar o mesmo codigo a cima com backtracking
    printf("nnh_backtracking solution: ");
}


void insercao_mais_proxima(int ** matriz_dist, int n){
    // criar ciclo tam 3
    printf("insercao_mais_proxima solution: ");
}

void insercao