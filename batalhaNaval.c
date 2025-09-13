#include <stdio.h>

int main() {
    char tabuleiro[10][10]; //Declara a matrix 10x10.
    int i, j; //Declara as variaveis para loops.

    // loop for para preencher '0' em todos espaços.
    for (i = 0; i < 10; i++){ //Loop para percorrer as linhas.
        for(j = 0; j < 10; j++){ //Loop para percorrer as colunas.
            tabuleiro[i][j] = '0';
        }
    }
    //Colocando os navios no tabuleiro.
    tabuleiro[0][3] = '3';
    tabuleiro[0][4] = '3';
    tabuleiro[0][5] = '3';

    tabuleiro[5][6] = '3';
    tabuleiro[6][6] = '3';
    tabuleiro[7][6] = '3';

    //Exibindo tabuleiro no terminal.

    printf("TABULEIRO BATALHA NAVAL:\n");
    printf("   ");
    for (j = 0; j < 10; j++){ //loop for A até J.
        printf("%1c ", 'A' + j);

    } 
    printf("\n");

    for (i = 0; i < 10; i++){ //Loop para percorrer as linhas.
        printf("%2d ", i + 1);
        for (j = 0; j < 10; j++){
            printf("%c ", tabuleiro[i][j]); //Imprime 0 ou 3.
        }
        printf("\n");
    }

    
    



    

    return 0;
}
