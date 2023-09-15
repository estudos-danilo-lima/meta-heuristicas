#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

#include "metaheuristics.h"

int main(){
    int n;

    scanf("%d%*c", &n);

    tGrafo g = criaGrafo(n);

    g = leMatrizAdjacencia(g);
    
    imprimeGrafo(g);
    nnh(g);


    liberaGrafo(g);
    return 0;
}