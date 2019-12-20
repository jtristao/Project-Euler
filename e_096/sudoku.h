#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

#define lin(pos) pos/DIM
#define col(pos) pos%DIM

#define DIM 9
#define ROOT 3

using namespace std;

/* Le uma matriz de tamanho DIM */
void sudoku_input(int **sudoku);

/* Verifica se o jogo já acabou */
bool is_over(int pos);

/* Resolve o tabuleiro de forma recursiva usando back_tracking e retorna o numero formado pelo 3 primeiros digitos */
int sudoku_back_tracking(int **sudoku, int pos);

/* Procura o tabuleiro por possíveis valores em certa posição */
void find_possible_numbers(unordered_set<int> &movements, int **sudoku, int pos);

/* Imprime uma matriz de tamanho DIM e suas posições */
void sudoku_full_print(int **sudoku);

/* Imprime o tabuleiro */
void sudoku_print(int **sudoku);


#endif