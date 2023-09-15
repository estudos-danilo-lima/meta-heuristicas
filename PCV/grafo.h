#ifndef _grafo
#define _grafo

typedef struct grafo * tGrafo;

tGrafo criaGrafo(int);
tGrafo leMatrizAdjacencia(tGrafo);

int getN(tGrafo);
int ** getMatrizAdjacencias(tGrafo);

void liberaGrafo(tGrafo);
void imprimeGrafo(tGrafo);

#endif