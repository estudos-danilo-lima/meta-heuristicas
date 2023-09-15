#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct grafo{
    int n;
    int ** matriz_adjacencias;
};

int getN(tGrafo g){
    return g->n;
}

int ** getMatrizAdjacencias(tGrafo g){
    return g->matriz_adjacencias;
}

tGrafo criaGrafo(int n){
    tGrafo novo = (tGrafo) malloc(sizeof(struct grafo));
    
    novo->n = n;
    
    novo->matriz_adjacencias = (int**) malloc(sizeof(int*) * novo->n);
    for(int i = 0; i < novo->n; i++){
        novo->matriz_adjacencias[i] = (int*) malloc(sizeof(int) * novo->n);
    }

    return novo;
}

tGrafo leMatrizAdjacencia(tGrafo g){
    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            scanf("%d%*c", &g->matriz_adjacencias[i][j]);
        }
    }

    return g;
}

void imprimeGrafo(tGrafo g){
    printf("Grafo n = %d\n", g->n);
    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            printf("%d ", g->matriz_adjacencias[i][j]);
        }
        printf("\n");
    }
}

void liberaGrafo(tGrafo g){
    for(int i = 0; i < g->n; i++){
        free(g->matriz_adjacencias[i]);
    }
    free(g->matriz_adjacencias);
    free(g);
}