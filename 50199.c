#include <stdio.h>

int main(){
	int r, c;
	scanf("%d%d", &r, &c);

	int candy[r+2][c+2];
	int i, j;
	for(i=0;i<r+2;i++){
		for(j=0;j<c+2;j++){
			if(i==0 || i==r+1 || j==0 || j==c+1){
				candy[i][j] = 0;
			}
			else{
				scanf("%d", &candy[i][j]);
			}
			
		}
	}

	for(i=1 ; i<r+1 ; i++){
		for(j=1 ; j<c+1 ; j++){
			int a = 0, b = 0, c = 0, d = 0;
			if(candy[i][j] == candy[i][j+1]) a = 1;
			if(candy[i][j] == candy[i][j-1]) b = 1;
			if(candy[i][j] == candy[i+1][j]) c = 1;
			if(candy[i][j] == candy[i-1][j]) d = 1;

			if(a+b+c+d == 2){
				candy[i][j] = 0;
				if(a == 1) candy[i][j+1] = 0;
				if(b == 1) candy[i][j-1] = 0;
				if(c == 1) candy[i+1][j] = 0;
				if(d == 1) candy[i-1][j] = 0;
			}
		}
	}



	for(i=1;i<r;i++){
		for(j=1;j<c;j++){
			printf("%d ", candy[i][j]);
		}
		printf("%d", candy[i][c]);
		printf("\n");
	}
	for(j=1;j<c+1;j++){
		printf("%d ", candy[r][j]);
	}

	return 0;
}