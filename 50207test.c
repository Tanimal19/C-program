# include<stdio.h>
# include<stdlib.h>
# define MAX 10
# define ROW 3
# define COL 5
 
typedef int A[ROW][COL];
typedef int B[COL][ROW];
typedef int C[ROW][ROW];
 
void multiplyMatrix(void **arrayA, void **arrayB, void **arrayC)
{
  A **aptr = (A **)arrayA; 
  B **bptr = (B **)arrayB;
  C **cptr = (C **)arrayC;

  for (; *aptr != NULL; aptr++, bptr++, cptr++) 
    for (int r = 0; r < ROW; r++)
      for (int c = 0; c < ROW; c++) {
        (**cptr)[r][c] = 0;             //(**cptr)[r][c] 相當於 MatrixC[0][r][c] 
        for (int k = 0; k < COL; k++) {
            (**cptr)[r][c] += (**aptr)[r][k] * (**bptr)[k][c];
        }
     }
}

int main() {
    int size = 0;
    scanf("%d", &size);
 
    void ** arrayA = malloc((size + 1) * sizeof(int*));
    void ** arrayB = malloc((size + 1) * sizeof(int*));
    void ** arrayC = malloc((size + 1) * sizeof(int*));
 
    A matrixA[MAX];
    B matrixB[MAX];
    C matrixC[MAX];
    for (int n = 0; n < size; n++) {
        for (int i = 0; i < ROW; i++) 
            for (int j = 0; j < COL; j++) 
                scanf("%d", &matrixA[n][i][j]);
 
        for (int i = 0; i < COL; i++) 
            for (int j = 0; j < ROW; j++) 
                scanf("%d", &matrixB[n][i][j]);
 
        arrayA[n] = &matrixA[n];
        arrayB[n] = &matrixB[n];
        arrayC[n] = &matrixC[n];
    }
 
    arrayA[size] = NULL;
    arrayB[size] = NULL;
    arrayC[size] = NULL;
 
    multiplyMatrix(arrayA, arrayB, arrayC);
 
    for (int n = 0; n < size; n ++) {
        for (int i = 0; i < ROW; i ++) {
            for (int k = 0; k < ROW; k++) {
                printf("%d ", matrixC[n][i][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
 
    return 0;
}