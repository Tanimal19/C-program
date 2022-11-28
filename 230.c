#include <stdio.h>
#define OBSIZE 20

int backpack(int i, int object[OBSIZE][2], int W, int value){
	if(W < 0) return -1;
	if(W > 0 && i < 20){
		// choose object[i]
		int L = backpack(i+1, object, W-object[i][0], value+object[i][1]);
		// not choose 
		int R = backpack(i+1, object, W, value);
		return L>=R ? L : R;
	}
	return value;
}

int main(){
	int n, W;
	scanf("%d%d", &n, &W);
	int object[OBSIZE][2] = {{0}};
	for(int i=0 ; i<n ; i++)
		scanf("%d%d", &object[i][0], &object[i][1]);

	printf("%d", backpack(0, object, W, 0));
	return 0;
}