#include <stdio.h>

int main(){
	char c;
	while(1){
		int sum = 0;
		int dif = 0;
		int digit = 0;
		int divisible[4] = {0};

		do{
			scanf("%c", &c);
			if(c == '-') return 0;

			if(c != '\n'){
				c -= 48;
				sum += c;
				dif += digit%2==0 ? c : -c;
				divisible[0] = c%2==0 ? 1 : 0;
				divisible[2] = (c == 5 || c == 0) ? 1 : 0;
			}
			digit ++;
		}while(c != '\n');

		if(sum % 3 == 0) divisible[1] = 1;
		if(dif % 11 == 0) divisible[3] = 1;
		for(int i=0 ; i<4 ; i++){
			if(divisible[i] == 1){
				printf("yes");
			}
			else{
				printf("no");
			}
			printf("%c", i==3 ? '\n' : ' ');
		}
	}
	return 0;
}