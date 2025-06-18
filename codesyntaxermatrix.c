#include <stdio.h>

void matrix(int r1, int c1, int r2, int c2,
            int A[r1][c1], int B[r2][c2], int C[r1][c2])
{
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main(void)
{
    int r1, c1, r2, c2;

    while (1)
    {
        printf("\nEnter rows of first matrix: ");
        scanf("%d", &r1);
        while (getchar() != '\n')
            ;
        printf("Enter columns of first matrix: ");
        scanf("%d", &c1);
        while (getchar() != '\n')
            ;
        printf("Enter rows of second matrix: ");
        scanf("%d", &r2);
        while (getchar() != '\n')
            ;
        printf("Enter columns of second matrix: ");
        scanf("%d", &c2);
        while (getchar() != '\n')
            ;
        if (c1 != r2)
        {
            printf("Error: columns of A (%d) do not match rows of B (%d). Try again.\n", c1, r2);
        }
        else
            break;
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];

    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
        {
            printf("A[%d][%d]: ", i + 1, j + 1);
            while (scanf("%d", &A[i][j]) != 1)
            {
                printf("Invalid number. Re-enter A[%d][%d]: ", i + 1, j + 1);
                while (getchar() != '\n')
                    ;
            }
            while (getchar() != '\n')
                ;
        }

    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
        {
            printf("B[%d][%d]: ", i + 1, j + 1);
            while (scanf("%d", &B[i][j]) != 1)
            {
                printf("Invalid number. Re-enter B[%d][%d]: ", i + 1, j + 1);
                while (getchar() != '\n')
                    ;
            }
            while (getchar() != '\n')
                ;
        }

    matrix(r1, c1, r2, c2, A, B, C);

    printf("\nResult matrix (%dx%d):\n", r1, c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%6d", C[i][j]);
        printf("\n");
    }

    return 0;
}
