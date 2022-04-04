#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, x, z;
    int faces, soma, rolagem;
    do {
        printf("Quantas faces no dado que voce deseja rolar?\n");
        printf("(Opcoes: 4, 6, 8, 10, 12 e 20) ");
        scanf("%d", &faces);
        if (faces !=4 && faces !=6 && faces !=8 && faces !=10 && faces !=12 && faces !=20) {
            printf("Opcao invalida!\n");
        }
    } while (faces !=4 && faces !=6 && faces !=8 && faces !=10 && faces !=12 && faces !=20);
    soma = (a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+x+z);
    if (soma < 0) { 
        soma *= -1;
    }
    rolagem = (soma % faces) + 1;
    printf("Resultado da rolagem do D%d: %d", faces, rolagem);
    return 0;
}
