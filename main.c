#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 10

void setRandomObstacle(char parts[TAM][TAM], int qtyObstacles);
void clear(char parts[TAM][TAM]);
void table(char parts[TAM][TAM]);
void setWorn(char parts[TAM][TAM]);

int main()
{
    setlocale(LC_ALL, "");

    int qtyObstacles = 0;

    printf("BEM-VINDO(A) AO\n");
    printf("PASSEIO DA MINHOCA DESGOVERNADA\n\n");
    printf("Digite quantos obstáculos o tabuleiro deve ter: ");
    scanf("%d", &qtyObstacles);

    // Workaround devido ao problema de C não
    // limpar a memória que aloca para as variáveis
    char parts[TAM][TAM];
    clear(parts);

    setRandomObstacle(parts, qtyObstacles);
    table(parts);

    setWorn(parts);
    table(parts);

    int moviments = 0;
    printf("Digite quantos movimentos a minhoca pode realizar: ");
    scanf("%d", &moviments);




    return 0;
}

// Cria obstáculos de forma aleatória
void setRandomObstacle(char parts[TAM][TAM], int qtyObstacles)
{
    for(int i = 0; i < qtyObstacles; i ++)
    {
        int seed = i;

        srand((time(NULL) * seed));
        int line = rand() % TAM;
        int column = rand() % TAM;

        // Verifica se espaço já foi preenchido
        if (parts[line][column] != ' ')
        {
            i--;
            continue;
        }

        parts[line][column] = 'X';
    }
}

// Limpa matriz
void clear(char parts[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            parts[i][j] = ' ';
        }
    }
}

// Mostra tabuleiro
void table(char parts[TAM][TAM])
{
    printf("\n================= TABULEIRO =================\n\n");

    int firtLine = 0, lantLine = (TAM - 1);
    for(int i = 0; i < TAM; i++ )
    {
        if (i == firtLine) printf("    ", i);
        printf(" %d  ", i);
        if (i == lantLine) printf("\n");

    }
    printf("   -----------------------------------------\n");
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if (j == firtLine) printf(" %d |", i);
            printf(" %c |", parts[i][j]);
        };
        printf("\n");
        printf("   -----------------------------------------\n");
    };
}

// Coloca a minhoca no tabuleiro
void setWorn(char parts[TAM][TAM])
{
    int line = 0, column= 0;

    do
    {
        printf("Digite a LINHA para a posição em que a minhoca deve começar: ");
        scanf("%d", &line);

        printf("Digite a COLUNA para a posição em que a minhoca deve começar: ");
        scanf("%d", &column);
    }
    while( parts[line][column] != ' ');

    parts[line][column] = 'C';

//    parts[line][( column - 1)] = '*';
//    parts[line][( column - 2)] = '*';
//    parts[line][( column - 3)] = '*';
//    parts[line][( column - 4)] = 'O';
}
