#include <stdio.h>

int numberbit(int num){
	int bit = 0;
	int maxbit = 0;

	for(int i=0 ; i<32 ; i++){
		if((num & 1) != 0){
			bit ++;
		}
		else{
			if(bit >= maxbit) maxbit = bit;
			bit = 0;
		}
		num >>= 1;
	}
	return maxbit;
}

int main(){
	int num;
	while(scanf("%d", &num) != EOF){
		printf("%d\n", numberbit(num));
	}
	return 0;
}