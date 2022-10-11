#include <stdio.h>

int main(){
	int x, y;
	int maxx = -10000,
		maxy = -10000,
		minx = 10000,
		miny = 10000;
	
	while(scanf("%d %d", &x, &y) != EOF){
		if(x >= maxx){
			maxx = x;
		}
		if(x <= minx){
			minx = x;
		}
		if(y >= maxy){
			maxy = y;
		}
		if(y <= miny){
			miny = y;
		}
	}

	int area = (maxx-minx)*(maxy-miny);
	printf("%d", area);
	return 0;
}