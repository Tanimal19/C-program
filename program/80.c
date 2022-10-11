#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int line;
	int ax, ay, bx, by, cx, cy;
	int a, b, c;

	scanf("%d", &line);
	int ans[line];

	for(int i=0;i<=line-1;i++){
		scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
		a=0; b=0; c=0;
		a=pow((bx-ax),2)+pow((by-ay),2);
		b=pow((cx-bx),2)+pow((cy-by),2);
		c=pow((ax-cx),2)+pow((ay-cy),2);
		
		int max;
		if(a<b||a<c){
			if(b<c){
				max=c; c=a;	a=max; 
			}else{
				max=b; b=a; a=max;
			}
		}
		#ifdef DEBUG
		printf("%d %d %d\n", a, b, c);
		#endif

		if(b==c||b==c||c==a){ 	//isosceles
			ans[i]=1;
		}
		else if(b+c<a){ 		//obtuse
			ans[i]=2;
		}
		else if(b+c>a){			//acute
			ans[i]=3;
		}
		else if(b+c==a){		//right
			ans[i]=4;
		}
	}
	for(int i=0;i<=line-1;i++){
		switch(ans[i]){
			case 1:
				printf("isosceles\n");
				break;
			case 2:
				printf("obtuse\n");
				break;
			case 3:
				printf("acute\n");
				break;
			case 4:
				printf("right\n");
				break;
		}
	}
	return 0;
}
