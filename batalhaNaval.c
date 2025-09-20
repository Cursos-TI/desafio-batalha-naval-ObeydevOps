#include <stdio.h>
#define LINHAS 10  //Declara as matrizes com 10 linhas
#define COLUNAS 10 //Declara as matrizes com 10 colunas
 
int main() {
    int tabuleiro [LINHAS][COLUNAS];
    int i, j; //Declara as variaveis para loop
       
        //Loop for para preencher '0' em todos os espaços
        for (int i = 0; i < LINHAS; i++) { //loop para percorer as linhas
            for (int j = 0; j < COLUNAS; j++) { //Loop para percorrer as colunas
                
               
                tabuleiro[i] [j] = '0';
                
                
            }
         
        }
        //Navio horizontal
        tabuleiro[0][3] = '3';
        tabuleiro[0][4] = '3';
        tabuleiro[0][5] = '3';
        
        //Navio vertical
        tabuleiro[5][6] = '3';
        tabuleiro[6][6] = '3';
        tabuleiro[7][6] = '3';
       
        //Navio diagonal 1
        tabuleiro[6][1] = '3';
        tabuleiro[5][2] = '3';
        tabuleiro[4][3] = '3';
        
        //Navio diagonal 2
        tabuleiro[2][7] = '3';
        tabuleiro[3][8] = '3';
        tabuleiro[4][9] = '3';
        
        //Exibindo tabuleiro no terminal!
        
        printf("TABULEIRO BATALHA NAVAL:\n");
    printf("   ");
    for (j = 0; j < COLUNAS; j++){ //loop for A até J.
        printf("%1c ", 'A' + j);

    } 
    printf("\n");

    for (i = 0; i < LINHAS; i++){ //Loop para percorrer as linhas.
        printf("%2d ", i + 1);
        for (j = 0; j < COLUNAS; j++){
            printf("%c ", tabuleiro[i][j]); //Imprime 0 ou 3.
        }
        printf("\n");
    }
     
     
     
     
     return 0;
}