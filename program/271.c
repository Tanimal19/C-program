#include <stdio.h>

int main(){
	int i, j;

	int n;
	scanf("%d", &n);
	int poly1[n];
	for(i=0;i<n;i++){
		scanf("%d", &poly1[i]);
	}

	int m;
	scanf("%d", &m);
	int poly2[m];
	for(i=0;i<m;i++){
		scanf("%d", &poly2[i]);
	}

	int poly3[m+n-1];
	for(i=0;i<m+n-1;i++){
		poly3[i] = 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			poly3[i+j] += poly1[i]*poly2[j];
		}
	}

	for(i=0;i<m+n-2;i++){
		printf("%d ", poly3[i]);
	}
	printf("%d", poly3[m+n-2]);
	return 0;
}