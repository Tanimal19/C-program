#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c;
	int j=0;
	int ans[3];
	scanf("%d%d%d", &a, &b, &c);

	for(int i=1;i<=c;i++){
		if(c%i==0){
			if((pow(-i,3) + pow(-i,2)*a + -i*b + c) == 0){
				ans[j]=i;
				j++;
			}
		}
	}
	printf("%d %d %d", ans[0], ans[1], ans[2]);
	return 0;
}
