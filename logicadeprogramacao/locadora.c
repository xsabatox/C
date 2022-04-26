#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    double versao = 1.0;
    int menu1 = 0, menu2 = 0, i, dias = 0, sucesso = 0;
    char nome[51];
    struct tm *devolucao;

    struct ficha {
        int emUso;
        int alugado;
        char nome[51];
        double preco;
        time_t locacao;
        time_t devolucao;
    };
    struct ficha catalogo[1000] = {0};

    do {
        do {
            printf("\nLOCADORA DE FILMES %.1lf\n", versao);
            printf("0 - Encerrar o programa\n"
                "1 - Cadastrar um filme\n"
                "2 - Pesquisar um filme\n"
                "3 - Alterar um filme\n"
                "4 - Excluir um filme\n");
            scanf("%d", &menu1);
        } while (menu1 < 0 || menu1 > 4);
        if (menu1 == 1) {
            for (i = 0; i < 1000; i++) {
                if (catalogo[i].emUso == 0) {
                    printf("\nCADASTRAR UM FILME\n");
                    printf("Digite o nome do filme:\n");
                    setbuf(stdin, NULL);
                    fgets(catalogo[i].nome, 50, stdin);
                    strtok(catalogo[i].nome, "\n");
                    printf("Digite o preco de locacao:\n");
                    scanf("%lf", &catalogo[i].preco);
                    sucesso = 1;
                    break;
                }
            }
            if (sucesso == 1) {
                printf("Filme cadastrado com sucesso.\n");
                sucesso = 0;
            } else {
                printf("Nao ha mais espaco para cadastrar novos filmes.\n");
            }
        }
        if (menu1 == 2) {
            printf("\nPESQUISAR UM FILME\n");
            printf("Digite o nome do filme:\n");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            strtok(nome, "\n");
            for (i = 0; i < 10; i++) {
                if ((strncmp(nome, catalogo[i].nome, 50) == 0) && catalogo[i].alugado == 0) {
                    printf("O filme \"%s\" esta disponivel.\n", catalogo[i].nome);
                    do {
                        do {
                            printf("0 - Sair\n"
                                "1 - Alugar\n");
                            scanf("%d", &menu2);
                            if (menu2 < 0 || menu2 > 1) {
                                printf("Opcao invalida.\n");
                            }
                        } while (menu2 < 0 || menu2 > 1);
                        if (menu2 == 1) {
                            do {
                                printf("Quantos dias deseja alugar o filme?\n");
                                scanf("%d", &dias);
                                if (dias < 1) {
                                    printf("Numero de dias invalido.\n");
                                }
                            } while (dias < 1);
                            catalogo[i].locacao = time(0);
                            catalogo[i].devolucao = catalogo[i].locacao + (dias * 86400);
                            catalogo[i].alugado = 1;
                            printf("Filme \"%s\" alugado com sucesso.\n", catalogo[i].nome);
                            devolucao = localtime(&catalogo[i].devolucao);
                            printf("Data da devolucao: %d/%d/%d\n",
                                devolucao -> tm_mday,
                                devolucao -> tm_mon + 1,
                                devolucao -> tm_year + 1900);
                            printf("Valor da locacao: R$ %.2lf\n", catalogo[i].preco);
                            break;
                        }
                    } while (menu2 != 0);
                    sucesso = 1;
                } else if ((strncmp(nome, catalogo[i].nome, 50) == 0) && catalogo[i].alugado == 1) {
                    devolucao = localtime(&catalogo[i].devolucao);
                    printf("O filme \"%s\" encontra-se alugado e estara disponivel em %d/%d/%d.\n",
                        catalogo[i].nome,
                        devolucao -> tm_mday,
                        devolucao -> tm_mon + 1,
                        devolucao -> tm_year + 1900);
                    sucesso = 1;
                    do {
                        printf("0 - Sair\n"
                            "1 - Devolver\n");
                        scanf("%d", &menu2);
                        if (menu2 < 0 || menu2 > 1) {
                            printf("Opcao invalida.\n");
                        }
                    } while (menu2 < 0 || menu2 > 1);
                    if (menu2 == 1) {
                        catalogo[i].locacao = 0;
                        catalogo[i].devolucao = 0;
                        devolucao = localtime(&catalogo[i].devolucao);
                        catalogo[i].alugado = 0;
                        printf("O filme \"%s\" foi devolvido.\n", catalogo[i].nome);
                    }
                }
            }
            if (sucesso == 0) {
                printf("O filme \"%s\" nao consta no catalogo.\n", nome);
            }
            sucesso = 0;
        }
        if (menu1 == 3) {
            printf("\nALTERAR DADOS DE UM FILME\n");
            printf("Digite o nome do filme:\n");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            strtok(nome, "\n");
            for (i = 0; i < 1000; i++) {
                if (strncmp(nome, catalogo[i].nome, 50) == 0) {
                    printf("Altere o nome do filme:\n");
                    setbuf(stdin, NULL);
                    fgets(catalogo[i].nome, 50, stdin);
                    strtok(catalogo[i].nome, "\n");
                    printf("Altere o preco de locacao:\n");
                    scanf("%lf", &catalogo[i].preco);
                    sucesso = 1;
                    break;
                }
            }
            if (sucesso == 1) {
                printf("Filme alterado com sucesso.\n");
                sucesso = 0;
            } else {
                printf("Nao foi possivel encontrar o filme para alterar.\n");
            }
        }
        if (menu1 == 4) {
            printf("\nEXCLUIR UM FILME\n");
            printf("Digite o nome do filme:\n");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            strtok(nome, "\n");
            for (i = 0; i < 1000; i++) {
                if (strncmp(nome, catalogo[i].nome, 50) == 0) {
                    printf("Certeza que deseja excluir o filme \"%s\"?\n", catalogo[i].nome);
                    do {
                        printf("0 - Nao\n"
                            "1 - Sim\n");
                        scanf("%d", &menu2);
                        if (menu2 < 0 || menu2 > 1) {
                            printf("Opcao invalida.\n");
                        }
                    } while (menu2 < 0 || menu2 > 1);
                    if (menu2 == 1) {
                        catalogo[i].emUso = 0;
                        catalogo[i].alugado = 0;
                        strncpy(catalogo[i].nome, "", 1);
                        catalogo[i].preco = 0;
                        sucesso = 1;
                    }
                }
            }
            if (sucesso == 1) {
                printf("Filme excluido com sucesso.\n");
                sucesso = 0;
            } else {
                printf("Nenhum filme foi alterado.\n");
            }
        }
    } while (menu1 != 0);
    return 0;
}
