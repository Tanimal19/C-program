#include <stdio.h>
#include <string.h>
#define STRL 80  

int main(){
	int n;
	scanf("%d", &n);
	
	int i, j, k;
	for(i=0 ; i<n ; i++){
		int same = 0;
		int change = 0;

		char s1[STRL];
		char s2[STRL];
		scanf("%s", s1);
		scanf("%s", s2);

		if(strlen(s1) < strlen(s2)){
			char temp[STRL];
			strcpy(temp, s1);
			strcpy(s1, s2);
			strcpy(s2, temp);
		}

		if(strcmp(s1,s2) == 0) same = 1;

		if(strlen(s1) == strlen(s2)){
			same = 1;
			for(j=0 ; j<strlen(s1) ; j++){
				if(s1[j] != s2[j]){
					same = 0;
					if(s1[j] == s2[j+1] && s1[j+1] == s2[j] && change == 0){
						same = 1;
						change = 1;
						j++;
					}
				}
			}
		}
		else if( strlen(s1)-strlen(s2) == 1){
			int error = 0;
			same = 1;
			for(j=0,k=0 ; j<strlen(s1) ; j++,k++){
				if(s1[j] != s2[k]){
					if(error == 0){
						k--;
						error++;
					}
					else{
						same = 0;
						break;
					}
				}
			}
		}

		printf("%s\n", same==1 ? "yes" : "no" );
	}
	return 0;
}