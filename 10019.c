#include <stdio.h>
#include <ctype.h>

int main(){
	char c;
	int s[100];
	int i = 0;
	
	while(scanf("%c", &c) != EOF){
		s[i] = c;
		i++;
	}

	i--;
	while(isspace(s[i])){
		i--;
	}
	int end = i+1;


	int head = 0;
	while(isspace(s[head])){
		head++;
	}
	
	for(i=head ; i<end ; i++){
		printf("%c", s[i]);
	}

	return 0;
}