#include <stdio.h>

int main(){
	char c;
	int comma = 0, space = 0, sentence = 0;

	while(scanf("%c", &c) != EOF){

		if(comma == 1){	
			if(c == ' '){
				space ++;		
			}
			else if(c == '\n' && space == 0){
				sentence ++;
				comma = 0;
			}
			else{
				if(space >= 2) sentence ++;
				comma = 0;
				space = 0;
			}
		}

		if(c == '.') comma = 1;	
	}
	if(comma == 1) sentence ++;

	printf("%d", sentence);
	return 0;
}