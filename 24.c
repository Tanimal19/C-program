#include <stdio.h>

int main(){
	char c[100];
	scanf("%s", c);

	int i = 0, num = 0, alpha = 0, m = 0;
	while(c[i] != '\0'){
		if(c[i] >= 48 && c[i] <= 57){
			num ++;
		}
		else if((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122)){
			if(c[i] =='a' || c[i] =='e' || c[i] =='i' || c[i] =='o' || c[i] =='u' ||
				c[i] =='A' || c[i] =='E' || c[i] =='I' || c[i] =='O' || c[i] =='U'){
				m ++;
			}
			alpha ++;
		}
		i++;
	}
	printf("%d %d %d %d", num, alpha, m, alpha-m);

	return 0;
}