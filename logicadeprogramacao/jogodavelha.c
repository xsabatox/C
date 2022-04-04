#include <stdio.h>
#include <stdlib.h>

float versao = 1.0;
int i, j, jogadas, vez;
char jogador, matriz[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void tabuleiro() {
    i = 0;
    j = 0;
    printf("\n     0    1    2  \n");
    for (i = 0; i < 3; i++) {
        printf(" %d ", i);
        for (j = 0; j < 3; j++) {
            printf ("[ %c ]", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("JOGO DA VELHA - Versao %.1f\n", versao);
    tabuleiro();
    for (jogadas = 0; jogadas < 9; jogadas++) {
        if (vez % 2 == 0) {
            jogador = 'X';
        } else {
            jogador = 'O';
        }
        printf("\nJogador %c, digite a coordenada da casa que deseja marcar (linha e coluna): ", jogador);
        scanf("%d %d", &i, &j);
        if (((i >= 0 && i <= 2) && (j >= 0 && j <= 2)) && ((matriz[i][j] != 'X') && (matriz[i][j] != 'O'))) {
            matriz[i][j] = jogador;
            tabuleiro();
            vez = vez + 1;
        } else {
            printf("\nJOGADA INVALIDA!\n");
            jogadas = jogadas - 1;
        }
        if (((matriz[0][0] == matriz[1][1]) && (matriz[0][0] == matriz[2][2])) && (matriz[0][0] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[0][0]);
            return 0;
        } else if (((matriz[0][2] == matriz[1][1]) && (matriz[0][2] == matriz[2][0])) && (matriz[0][2] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[0][2]);
            return 0;
        } else if (((matriz[0][0] == matriz[0][1]) && (matriz[0][0] == matriz[0][2])) && (matriz[0][0] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[0][0]);
            return 0;
        } else if (((matriz[1][0] == matriz[1][1]) && (matriz[1][0] == matriz[1][2])) && (matriz[1][0] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[1][0]);
            return 0;
        } else if (((matriz[2][0] == matriz[2][1]) && (matriz[2][0] == matriz[2][2])) && (matriz[2][0] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[2][0]);
            return 0;
        } else if (((matriz[0][0] == matriz[1][0]) && (matriz[0][0] == matriz[2][0])) && (matriz[0][0] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[0][0]);
            return 0;
        } else if (((matriz[0][1] == matriz[1][1]) && (matriz[0][1] == matriz[2][1])) && (matriz[0][1] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[0][1]);
            return 0;
        } else if (((matriz[0][2] == matriz[1][2]) && (matriz[0][2] == matriz[2][2])) && (matriz[0][2] != ' ')) {
            printf("\nJogador %c ganhou!\n", matriz[0][2]);
            return 0;
        }
    }
    printf("\nJogo deu velha!\n");
    return 0;
}
