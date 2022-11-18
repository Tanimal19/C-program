#include <stdio.h>

int numberbit(int num){
	int bit = 0;
	for(int i=0 ; i<32 ; i++){
		if((num & 1) != 0) bit ++;
		num >>= 1;
	}
	return bit;
}

int main(){
	int num;
	while(scanf("%d", &num) != EOF){
		printf("%d\n", numberbit(num));
	}
	return 0;
}