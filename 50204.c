#include <stdio.h>

#define MAXL 100
#define MAXR 100
#define MAXC 100

void green(int cube[MAXL][MAXR][MAXC], int layer, int n);
void blue(int cube[MAXL][MAXR][MAXC], int layer, int n);

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	int cube[MAXL][MAXR][MAXC];	// [layer][row][column]
	int i, j, k;
	int num = 0;
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			for(k=0 ; k<n ; k++){
				cube[i][j][k] = num;
				num ++;
			}
		}
	}	

	int type, layer;
	for(i=0 ; i<m ; i++){
		scanf("%d%d", &type, &layer);
		if(type == 0){
			green(cube, layer, n);
		}
		else{
			blue(cube, layer, n);
		}
	}
	
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			for(k=0 ; k<n ; k++)
				printf("%d%c", cube[i][j][k], k==n-1 ? '\n':' ');

	return 0;
}

void green(int cube[MAXL][MAXR][MAXC], int layer, int n){
	int templayer[MAXR][MAXC];
	int i, j;

	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			templayer[j][n-i-1] = cube[layer][i][j];
		
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			cube[layer][i][j] = templayer[i][j];
		
	return;
}

void blue(int cube[MAXL][MAXR][MAXC], int layer, int n){
	int templayer[MAXR][MAXC];
	int i, j;

	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			templayer[j][n-i-1] = cube[n-j-1][i][layer];
		
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			cube[i][j][layer] = templayer[j][n-i-1];
		
	return;
}
