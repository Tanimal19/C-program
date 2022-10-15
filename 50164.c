#include <stdio.h>

int main(){
	int r, c;
	scanf("%d%d", &r, &c);

	int map[r][c];
	int i, j, k, l;
	int dice = 0;

	for(i=0 ; i<r ; i++){
		for(j=0 ; j<c ; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(i=1 ; i<r-1 ; i++){
		for(j=0 ; j<=c-4 ; j++){
			if( map[i][j+1] != map[i][j]  &&  map[i][j+1] + map[i][j] != 7 ){
				if( map[i][j] + map[i][j+2] == 7  &&  map[i][j+1] + map[i][j+3] == 7 ){
					for(k=0 ; k<4 ; k++){
						int same = 0;
						for(l=0 ; l<4 ; l++){
							if( map[i-1][j+k] == map[i][j+l] ) same=1;
						}
						if(same == 0){
							for(l=0 ; l<4 ; l++){
								if( map[i-1][j+k] + map[i+1][j+l] == 7 ){
									dice ++;
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%d", dice);
	return 0;
}