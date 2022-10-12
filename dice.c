#include <stdio.h>

int checkrow(int r, int c);

int main(){
	int r, c;
	scanf("%d%d", &r, &c);

	int map[r][c];
	int i, j;
	for(i=0 ; i<r ; i++){
		for(j=0 ; j<c ; j++){
			scanf("%d", &map[i][j]);
		}
	}

	int top, bot;

	for(i=1 ; i<r-1 ; i++){
		for(j=0 ; j<=c-4 ; j++){
			checkrow(i, j);
		}
	}
}


int checkrow(int r, int c){
	if( map[r][c+1] != map[r][c]  &&  map[r][c+1] != 7 - map[r][c] ){
		if( map[r][c] + map[r][c+2] == 7  &&  map[r][c+1] + map[r][c+3] == 7 ){
			return 1;
		}
	}
	return 0;
}

void checktopbot(int r, int c){
	
	for(i=0 ; i<4 ; i++){
		for(j=0 ; j<4 ; j++){
			if( map[r+1][c] ==  map[r][c+j] ){
				return 0;
			}
		}
		for(j=0 ; j<4 ; j++){
			if( map[r+1][c] + map[r-1][c+j] == 7 ){
				dice ++;
			}
		}
	}
	

	
}
