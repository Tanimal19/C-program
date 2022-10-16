#include <stdio.h>

int main(){
	int h, w, k;
	scanf("%d%d%d", &h, &w, &k);

	int matrix[h][w];
	int i, j;
	for(i=0 ; i<h ; i++){
		for(j=0 ; j<w ; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	int midy = k-1, midx;
	int size = k-1;

	int max = 0;
	int sum;
	while((midy + size) < h){
		midx = k-1;
		while((midx + size) < w){
			sum = 0;
			sum += ( matrix[midy + size][midx] + matrix[midy - size][midx] );
			sum += ( matrix[midy][midx + size] + matrix[midy][midx - size] );

			for(i=1 ; i<size ; i++){
				j = size - i;
				sum += ( matrix[midy - i][midx - j] + matrix[midy - i][midx + j] );
				sum += ( matrix[midy + i][midx - j] + matrix[midy + i][midx + j] );
			}

			if(sum >= max){
				max = sum;
			}
			midx ++;
		}
		midy ++;
	}

	printf("%d", max);
	return 0;
}