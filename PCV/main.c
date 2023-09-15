#include <stdio.h>
#include <stdlib.h>
#include "metaheuristics.h"

int ** leMatrizDistancias(int n){
    int ** nova = (int**) malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++){
        nova[i] = (int*) malloc(sizeof(int) * n);
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            scanf("%d%*c", &nova[i][j]);
        }
    }

    return nova;
}

void liberaMatrizDistancias(int ** md, int n){
    for(int i = 0; i < n; i++){
        free(md[i]);
    }
    free(md);
} 

int main(){
    int n;

    scanf("%d%*c", &n);
    int ** matriz_distancias = leMatrizDistancias(n);

    nnh(matriz_distancias, n);

    liberaMatrizDistancias(matriz_distancias, n);

    return 0;
}