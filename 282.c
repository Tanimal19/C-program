#include <stdio.h>

int numberbit(long long int num){
	int bit = 0;
	for(int i=0 ; i<64 ; i++){
		if((num & 1) != 0) bit ++;
		num >>= 1;
	}
	return bit;
}

int main(){
	long long int num;
	while(scanf("%lld", &num) != EOF){
		printf("%d\n", numberbit(num));
	}
	return 0;
}