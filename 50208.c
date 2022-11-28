#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	char key[4][10] = {"if", "while", "for", "case"};
	int complex = 0;

	while(scanf("%s", s) != EOF){
		for(int i=0; i<4 ; i++){
			char *p = strstr(s, key[i]);
			if(p != NULL){
				if(p == &s[0]){
					if(*(p+strlen(key[i])) == '\0' || *(p+strlen(key[i])) == '('){
						complex ++;
						#ifdef DEBUG 
						printf("\nfind\n");
						#endif
					}
				}
				else{
					if(*(p-1) == ')'){
						complex ++;
						#ifdef DEBUG 
						printf("\nfind\n");
						#endif
					} 
				}
			}

		}
		if(strchr(s, '?') != NULL){
			complex ++;
			#ifdef DEBUG 
			printf("\nfind\n");
			#endif
		}
	}
	printf("%d", complex);
	return 0;
}