#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int acao1, acao2, acao3, n, i, r;
    char nome[50];

    struct ficha {
        int mesa;
        char nome[50];
        double telefone;
    };
    struct ficha reserva[30] = {0};

    do {
        do {
            printf("\nRESERVA DE MESAS 1.0\n"
                "0 - Encerrar o programa\n"
                "1 - Realizar reserva\n"
                "2 - Verificar reserva\n"
                "3 - Remover reserva\n");
            scanf("%d", &acao1);
        } while (acao1 < 0 || acao1 > 3);
        if (acao1 == 1) {
            do {
                printf("\nREALIZAR RESERVA\n"
                       "Digite o numero da mesa que deseja reservar (100 a 129) ou 0 para sair:\n");
                scanf("%d", &n);
                if (n == 0) {
                    break;
                }
                if((n < 100 || n > 129) && n != 0) {
                    printf("Numero de mesa invalido para reservas. Tente novamente.\n");
                } else if(reserva[(n - 100)].mesa != 0) {
                    printf("Mesa ocupada. Tente novamente.\n");
                } else {
                    printf("Digite o nome da reserva: ");
                    setbuf(stdin, NULL);
                    fgets(reserva[(n - 100)].nome, 50, stdin);
                    strtok(reserva[(n - 100)].nome, "\n");
                    printf("Digite o numero do telefone de contato: ");
                    scanf("%lf", &reserva[(n - 100)].telefone);
                }
            } while (((n != 0) && (n < 100 || n > 129)) || (reserva[(n - 100)].mesa != 0));
            reserva[(n - 100)].mesa = 1;
            printf("Reserva concluida com sucesso.\n");
        }
        if (acao1 == 2) {
            do {
                do {
                    printf("\nVERIFICAR RESERVA\n"
                        "0 - Voltar\n"
                        "1 - Consultar por numero da mesa\n"
                        "2 - Consultar por nome da reserva\n");
                    scanf("%d", &acao2);
                } while (acao2 < 0 || acao2 > 2);
                if (acao2 == 1) {
                    do {
                        printf("\nVERIFICAR RESERVA PELO NUMERO DA MESA\n"
                               "Digite o numero da mesa reservada (100 a 129) ou 0 para sair:\n");
                        scanf("%d", &n);
                    } while ((n != 0) && (n < 100 || n > 129));
                    if ((n != 0) && (reserva[(n - 100)].mesa == 1)) {
                        printf("A mesa %d esta reservada para %s, telefone %0.lf.\n",
                        n, reserva[(n - 100)].nome, reserva[(n - 100)].telefone);
                    } else {
                        printf("Esta mesa nao esta reservada.\n");
                    }
                }
                if (acao2 == 2) {
                    printf("\nVERIFICAR RESERVA PELO NOME\n"
                           "Digite o nome da reserva\n");
                    setbuf(stdin, NULL);
                    fgets(nome, 50, stdin);
                    strtok(nome, "\n");
                    r = 0;
                    for (i=0; i<30; i++) {
                        if (strcmp(reserva[i].nome, nome)) {
                            // condicao se strings diferentes.
                        } else {
                            printf("%s, telefone %.0lf, reservou a mesa %d.\n",
                            reserva[i].nome, reserva[i].telefone, (i + 100));
                            r = 1;
                        }
                    }
                    if (r == 0) {
                        printf("Nao ha reserva para %s.\n", nome);
                    }
                }
            } while (acao2 != 0);
        }
        if (acao1 == 3) {
            do {
                printf("\nREMOVER RESERVA\n"
                    "0 - Voltar\n"
                    "1 - Remover usando o numero da mesa\n"
                    "2 - Remover usando o nome da reserva\n");
                scanf("%d", &acao3);
            } while (acao3 < 0 || acao3 > 2);
            if (acao3 == 1) {
                do {
                    printf("\nREMOVER RESERVA USANDO O NUMERO DA MESA\n"
                        "Digite o numero da mesa reservada (100 a 129) ou 0 para sair:\n");
                    scanf("%d", &n);
                } while ((n != 0) && (n < 100 || n > 129));
                if (n != 0) {
                    reserva[(n - 100)].mesa = 0;
                    strcpy(reserva[(n - 100)].nome, "");
                    reserva[(n - 100)].telefone = 0;
                    printf("Reserva removida com sucesso.\n");
                }
            }
            if (acao3 == 2) {
                printf("\nREMOVER RESERVA USANDO O NOME\n"
                    "Digite o nome da reserva\n");
                setbuf(stdin, NULL);
                fgets(nome, 50, stdin);
                strtok(nome, "\n");
            }
            r = 0;
            for (i=0; i<30; i++) {
                if (strcmp(reserva[i].nome, nome)) {
                    // condicao se strings diferentes.
                } else {
                    reserva[i].mesa = 0;
                    strcpy(reserva[i].nome, "");
                    reserva[i].telefone = 0;
                    printf("Reserva removida com sucesso.\n");
                    r = 1;
                }
            }
            if (r == 0) {
                printf("Nao ha reserva para %s.\n", nome);
            }
        }
    } while (acao1 != 0);
    return 0;
}
