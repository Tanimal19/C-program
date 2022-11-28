#include <stdio.h>
#include <string.h>
#define MAX 10000
#define STRLEN 31

int main(){
	char s[MAX][STRLEN];
	int i = 0;
	while(scanf("%s", s[i]) != EOF){
		i++;	
	}

	int star = 0;
	for(int n=0 ; n<i ; n++){
		int start = 0;
		if(n != 0 && s[n-1][strlen(s[n-1])-1] == s[n][0]) start = 1;

		if(n%2 == 0){
			if(n != 0 && start == 0){
				printf("\n");
				for(int k=0 ; k<star ; k++)
					printf("*");
			}
			printf("%s\n",s[n]+start);
			star += strlen(s[n]) - 1;
		}
		else{
			for(int j=start ; j<strlen(s[n]) ; j++){
				for(int k=0 ; k<star ; k++)
					printf("*");
				printf("%c", s[n][j]);
			
				if(j != strlen(s[n])-1) printf("\n");
			}
		}
	}
	return 0;
}