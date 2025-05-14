#include <stdio.h>

//Dinamismo no tamanho do tabuleiro
#define LINHA 10
#define COLUNA 10

int main() {
    int tabuleiro[LINHA][COLUNA] = {0};

    // Zerar o tabuleiro
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIOS
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][3] = 4; // navio vertical
    }
    for (int j = 4; j < 6; j++) {
        tabuleiro[4][j] = 1; // navio horizontal
    }
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 2; // diagonal principal
    }
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][9 - i] = 3; // diagonal secundária
    }

    // ATAQUE EM CONE (virado pra baixo)
    int j = 2;
    int i = 4;
    if (j + 2 < LINHA && i - 2 >= 0 && i + 2 < COLUNA) {
        tabuleiro[j][i] = 3;
        tabuleiro[j + 1][i] = 3;
        tabuleiro[j + 1][i - 1] = 9;
        tabuleiro[j + 1][i + 1] = 9;
        tabuleiro[j + 2][i - 2] = 9;
        tabuleiro[j + 2][i - 1] = 9;
        tabuleiro[j + 2][i] = 9;
        tabuleiro[j + 2][i + 1] = 9;
        tabuleiro[j + 2][i + 2] = 9;
    }

    // ATAQUE EM CRUZ
    j = 5;
    i = 5;
    if (j - 1 >= 0 && j + 1 < LINHA && i - 2 >= 0 && i + 2 < COLUNA) {
        tabuleiro[j][i - 2] = 8;
        tabuleiro[j][i - 1] = 8;
        tabuleiro[j][i] = 8;
        tabuleiro[j][i + 1] = 8;
        tabuleiro[j][i + 2] = 8;
        tabuleiro[j - 1][i] = 8;
        tabuleiro[j + 1][i] = 8;
    }

    // ATAQUE EM OCTAEDRO
    j = 7;
    i = 2;
    if (j - 1 >= 0 && j + 1 < LINHA && i - 1 >= 0 && i + 1 < COLUNA) {
        tabuleiro[j][i] = 7;
        tabuleiro[j - 1][i] = 7;
        tabuleiro[j + 1][i] = 7;
        tabuleiro[j][i - 1] = 7;
        tabuleiro[j][i + 1] = 7;
    }

    // EXIBIR CABEÇALHO COM LETRAS
    printf("     TABULEIRO NAVAL\n   ");
    for (char letra = 'A'; letra < 'A' + COLUNA; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // EXIBIR TABULEIRO
    for (int i = 0; i < LINHA; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
