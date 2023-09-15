#ifndef _mh
#define _mh

#define POS_INICIAL 0
#define LIVRE 0
#define USO 1


// Algoritmos Construtivos
void nnh(int **, int);
void nnh_backtracking(int **, int);
void insercao_mais_proxima(int **, int);
void insercao_mais_distante(int **, int);
void insercao_mais_barata(int **, int);
void economias(int **, int);

// Algoritmos de Busca Local
void hill_climbing(int **, int);
void steepest_descent(int **, int);


#endif