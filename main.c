// Adryane Cristine e Erik Correa

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

#define TAM 10
#define OBSTACLE 'X'
#define EMPTY_CHAR ' '
#define HEAD_WORM 'C'

void setRandomObstacle(char parts[TAM][TAM], int qtyObstacles);
void clear(char parts[TAM][TAM]);
void table(char parts[TAM][TAM]);

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

    // Criar os obstáculos
    setRandomObstacle(parts, qtyObstacles);
    table(parts);


    // Coloca a minhoca na tabela
    int x = 0, y= 0;

    do
    {
        printf("Digite a LINHA para a posição em que a minhoca deve começar: ");
        scanf("%d", &x);

        printf("Digite a COLUNA para a posição em que a minhoca deve começar: ");
        scanf("%d", &y);
    }
    while( parts[x][y] != EMPTY_CHAR);

    parts[x][y] = HEAD_WORM;

    table(parts);

    int moviments = 0;
    printf("\nDigite quantos movimentos a minhoca pode realizar: ");
    scanf("%d", &moviments);

    table(parts);
    printf("[w] - cima | [s] - baixo | [a] - esquerda | [d] - direita\n");

    for(int i = 1; i <= moviments; i++ )
    {
        char l = getch();
        putch(l);

        parts[x][y] = EMPTY_CHAR;
        int newX = x, newY = y;

        switch(l)
        {
        case 'w': // pra cima
            newX--;
            break;
        case 's': // pra baixo
            newX++;
            break;
        case 'd': // pra direita
            newY++;
            break;
        case 'a': // pra esquerda
            newY--;
            break;
        default:
            i--;
            break;
        }

        if (parts[newX][newY] != EMPTY_CHAR)
        {
            printf("\n\n !! Obstáculo a frente, siga outro caminho. !! \n\n ");
            i--;
            continue;
        }

        x = newX;
        y = newY;

        parts[x][y] = HEAD_WORM;
        table(parts);

        printf("[w] - cima | [s] - baixo | [a] - esquerda | [d] - direita\n");
    }


    printf("\nCasas visitadas: %d\n", moviments);
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
        if (parts[line][column] != EMPTY_CHAR)
        {
            i--;
            continue;
        }

        parts[line][column] = OBSTACLE;
    }
}

// Limpa matriz
void clear(char parts[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            parts[i][j] = EMPTY_CHAR;
        }
    }
}

// Mostra tabuleiro
void table(char parts[TAM][TAM])
{
    system("cls");
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
