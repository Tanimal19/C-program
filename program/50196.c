#include <stdio.h>

int main(){
	int n, number=0, sum=0, time=1; 

	while(scanf("%d", &n)){
		if(n==0){
			time *= number;
			sum += time;
			break;
		}
		
		if(n<8){
			number = number*10 + n;
		}
		else{
			time *= number;
			if(n==8){
				sum += time;
				time = 1;
			}
			number = 0;
		} 
	}
	printf("%d", sum);
	return 0;
} 