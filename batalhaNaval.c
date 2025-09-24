#include <stdio.h>

#define LINHAS 10      // Número de linhas do tabuleiro
#define COLUNAS 10     // Número de colunas do tabuleiro
#define TAMANHO 5      // Matrizes de habilidade (5x5)

int main() {
    char tabuleiro[LINHAS][COLUNAS]; // Tabuleiro
    int cone[TAMANHO][TAMANHO]; // cone
    int cruz[TAMANHO][TAMANHO]; // cruz
    int octa[TAMANHO][TAMANHO]; // octaedro
    int i, j; // Variáveis para loops

    // Inicializa tabuleiro com '0' 
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Colocando os navios no tabuleiro
    tabuleiro[0][3] = tabuleiro[0][4] = tabuleiro[0][5] = '3'; // Navio horizontal
    tabuleiro[7][3] = tabuleiro[8][3] = tabuleiro[9][3] = '3'; // Navio vertical
    tabuleiro[6][1] = tabuleiro[5][2] = tabuleiro[4][3] = '3'; // Navio diagonal 1
    tabuleiro[2][7] = tabuleiro[3][8] = tabuleiro[4][9] = '3'; // Navio diagonal 2

    // Inicializa matrizes de habilidade com '0'
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octa[i][j] = 0;
        }
    }

    // Define habilidade cone
    cone[0][2] = 5; // Topo do cone
    cone[1][1] = cone[1][2] = cone[1][3] = 5; // Meio
    cone[2][0] = cone[2][1] = cone[2][2] = cone[2][3] = cone[2][4] = 5; // Base

    // Define habilidade cruz
    cruz[0][2] = 5; 
    for (j = 0; j < TAMANHO; j++) {
        cruz[1][j] = 5; 
    }
    cruz[2][2] = 5; 

    // Define habilidade octaedro
    octa[1][2] = 5;
    octa[2][1] = octa[2][2] = octa[2][3] = 5;
    octa[3][2] = 5; 
    
    // Cone no tabuleiro
    int linha = 2, coluna = 2; 
    int inicioLinha = linha - TAMANHO / 2;
    int inicioColuna = coluna - TAMANHO / 2;
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            int linhaTabuleiro = inicioLinha + i;
            int colunaTabuleiro = inicioColuna + j;
            if (linhaTabuleiro >= 0 && linhaTabuleiro < LINHAS && colunaTabuleiro >= 0 && colunaTabuleiro < COLUNAS) {
                if (cone[i][j] == 5 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != '3') {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = '5';
                }
            }
        }
    }

    // Cruz no tabuleiro
    linha = 5; coluna = 5; 
    inicioLinha = linha - 3 / 2; 
    inicioColuna = coluna - TAMANHO / 2;
    for (i = 0; i < 3; i++) { 
        for (j = 0; j < TAMANHO; j++) {
            int linhaTabuleiro = inicioLinha + i;
            int colunaTabuleiro = inicioColuna + j;
            if (linhaTabuleiro >= 0 && linhaTabuleiro < LINHAS && colunaTabuleiro >= 0 && colunaTabuleiro < COLUNAS) {
                if (cruz[i][j] == 5 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != '3') {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = '5';
                }
            }
        }
    }

    // Octaedro no tabuleiro
    linha = 8; coluna = 8; 
    inicioLinha = linha - TAMANHO / 2;
    inicioColuna = coluna - TAMANHO / 2;
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            int linhaTabuleiro = inicioLinha + i;
            int colunaTabuleiro = inicioColuna + j;
            if (linhaTabuleiro >= 0 && linhaTabuleiro < LINHAS && colunaTabuleiro >= 0 && colunaTabuleiro < COLUNAS) {
                if (octa[i][j] == 5 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != '3') {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = '5';
                }
            }
        }
    }

    // Exibe tabuleiro com habilidades
    printf("\nTABULEIRO BATALHA NAVAL:\n");
    printf("   ");
    for (j = 0; j < COLUNAS; j++) {
        printf("%c ", 'A' + j); // Imprime A a J
    }
    printf("\n");
    for (i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1); // Imprime número da linha
        for (j = 0; j < COLUNAS; j++) {
            printf("%c ", tabuleiro[i][j]); // Imprime 0, 3 ou 5
        }
        printf("\n");
    }

    return 0;
}