#include <stdio.h>
#include <stdlib.h>

#define NUMX 3
#define NUMY 3

// Procedimento para imprimir o tabuleiro original
void imprimirtabuleiro(int vec[NUMX][NUMY])
{
    int i, j;
    for (i = 0; i < NUMX; i++)
    {
        for (j = 0; j < NUMY; j++)
        {
            vec[i][j] = '_';
            printf("%c ", vec[i][j]);
        }
        printf("\n");
    }
}

/*Procedimento para verificar se as coordenadas estão vazias, ou seja, com _.
Verifica também se o jogador anterior não jogou para aquela casa. Caso tenha jogado volta a repetir a pergunta*/
void escolherCoordenada(int vec[NUMX][NUMY])
{
    int i, j, x, y, numJogado;

    do
    {

        if (vec[i][j] == '_')
        {
            printf("\nEscolha as coordenadas:\n");
        }

        printf("\nIndique a coordenada X que deseja (1 a 3): ");
        scanf("%d", &x);
        x = x - 1;
        printf("\nIndique a coordenada Y que deseja (1 a 3): ");
        scanf("%d", &y);
        y = y - 1;

    } while (vec[x][y] == '1' || vec[x][y] == '2');
}

// Procedimento para imprimir o tabuleiro a cada jogada dos jogadores
void imprimirNovoTabuleiro(int vec[NUMX][NUMY], char numJogado)
{
    int i, j, x, y;

    for (i = 0; i < NUMX; i++)
    {
        for (j = 0; j < NUMY; j++)
        {

            vec[x][y] = numJogado;
            printf("%c ", vec[i][j]);
        }
        printf("\n");
    }
}

// Procedimento para verificar se o tabuleiro está completo
void verificarTabuleiro(int vec[NUMX][NUMY])
{
    int i, j;

    if (vec[i][j] != '_')
    {
        printf("\nTodas as coordenadas ja foram preenchidas! O jogo terminou!");
    }
}

int main()
{
    int vec[NUMX][NUMY], i, j;
    int xjogadas = 1;

    char player1[50];
    char player2[50];
    int numJogado = 0;
    int playerNbr = 1;
    int x, y;

    printf("Introduza o nome do Player 1: ");
    scanf("%s", &player1);

    printf("Introduza o nome do Player 2: ");
    scanf("%s", &player2);

    printf("\nTabuleiro: \n");
    imprimirtabuleiro(vec);

    if (playerNbr = 1)
    {
        printf("\nVez do Jogador: %s", player1);
        // inserirValTabuleiro(vec);
        escolherCoordenada(vec);
        numJogado = '1';
        imprimirNovoTabuleiro(vec, numJogado);
    }

    // Alternância entre jogadores
    do
    {
        if (numJogado == '1')
        {
            printf("\nVez do Jogador: %s\n", player2);
            // inserirValTabuleiro(vec);
            escolherCoordenada(vec);
            numJogado = '2';
            imprimirNovoTabuleiro(vec, numJogado);
            xjogadas++;
        }
        if (numJogado == '2')
        {
            printf("\nVez do Jogador: %s\n", player1);
            // inserirValTabuleiro(vec);
            escolherCoordenada(vec);
            numJogado = '1';
            imprimirNovoTabuleiro(vec, numJogado);
            xjogadas++;
        }
    } while (xjogadas != 9);

    verificarTabuleiro(vec);

    return 0;
}