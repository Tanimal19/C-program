#include <stdio.h>
#include <string.h>

int main(){
	char keyboard[60] = "0000000000000qwertyuiop00asdfghjkl000zxcvbnm0000000000000000";

	char word;
	scanf("%c", &word);
	char *now = strchr(keyboard, word);
	char output[1000];
	output[0] = word;
	int i=1;
	
	int n;
	while(scanf("%d", &n) != EOF){
		int direct = 0;
		
		switch(n){
			case 0:
				direct = 1;
				break;
			case 1:
				direct = -11;
				break;
			case 2:
				direct = -12;
				break;
			case 3:
				direct = -1;
				break;
			case 4:
				direct = 11;
				break;
			case 5:
				direct = 12;
				break;
			default:
				break;
		}

		if(*(now + direct) != '0'){
			now += direct;
			output[i] = *now;
			i++;
		}
	}
	for(int j=0 ; j<i ; j++){
		printf("%c\n", output[j]);
	}

	return 0;
}