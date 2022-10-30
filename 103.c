#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int i, j;
	double A[n][n];
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			scanf("%lf", &A[i][j]);

	double y[n];
	for(i=0 ; i<n ; i++)
		scanf("%lf", &y[i]);

	double x[n];
	for(i=n-1 ; i>=0 ; i--){
		j = n-1;
		x[i] = y[i];
		while(A[i][j-1] != 0){
			x[i] -= A[i][j]*x[j];
			j--;
		}
		x[i] /= A[i][j];
	}

	for(i=0 ; i<n ; i++)
		printf("%f\n", x[i]);

	return 0;
}