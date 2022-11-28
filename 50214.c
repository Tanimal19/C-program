#include <stdio.h>
#define MSIZE 8

int determinant(int p, int matrix[MSIZE][MSIZE], int n){
	int sum = 0;
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			printf("%d%c", matrix[i][j], j==n-1 ? '\n':' ');

	if(n == 1) return matrix[0][0] * p;

	for(int i=0 ; i<n ; i++){
		int smatrix[MSIZE][MSIZE];

		for(int j=1, a=0 ; j<n ; j++, a++){
			int b = 0;
			for(int k=0; k<n ; k++){
				if(k != i){
					smatrix[a][b] = matrix[j][k];
					b++;
				}
			}
		}

		#ifdef PRINT_SMATRIX
		for(int i=0 ; i<n-1 ; i++)
			for(int j=0 ; j<n-1 ; j++)
				printf("%p%c", &smatrix[i][j], j==n-2 ? '\n':' ');
		#endif

		sum += i%2==0 ? determinant(matrix[0][i], smatrix, n-1) : -determinant(matrix[0][i], smatrix, n-1);
	}

	printf("determinant=%d\n", sum);
	return sum;
}

int main(){
	int n;
	scanf("%d", &n);
	int matrix[MSIZE][MSIZE];
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			scanf("%d", &matrix[i][j]);

	determinant(0 , matrix, n);
	return 0;
}