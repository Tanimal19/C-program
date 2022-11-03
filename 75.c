#include <stdio.h>

int main(){
	char c;
	int n[128] = {0};
	while(scanf("%c", &c) != EOF){
		n[c]++;
	}
	int i;
	for(i=0 ; i<26 ; i++){
		printf("%d", n[i+65] + n[i+97]);
		if(i != 25)	printf("\n");
	}
	return 0;
}