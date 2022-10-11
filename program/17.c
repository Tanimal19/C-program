#include <stdio.h>

int main(){
	int r, c;
	scanf("%d%d", &r, &c);

	int arr[r][c];
	int i, j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d", &arr[i][j]);
		}
	}

	for(i=0;i<c;i++){
		int sum = 0;
		for(j=0;j<r;j++){
			sum += arr[j][i];
		}
		printf("%d\n", sum/r);
	}

	return 0;
}