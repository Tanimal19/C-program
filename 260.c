#include <stdio.h>
#include <string.h>
#define STRSIZE 128

int main(){
	char full[STRSIZE];
	char new[STRSIZE];
	int i;

	scanf("%s", full);
	char *end = &( full[strlen(full)] );

	while(scanf("%s", new) != EOF){
		int find = 0;
		char *repeat = full;
		char *contact = new;
		int first = 0;

		while(find != 1){
			if(first != 0){
				repeat = repeat + 1;
			}
			repeat = strchr(repeat, new[0]);
			

			if(repeat != NULL){
				i = 0; 
				while(repeat+i != end && i<strlen(new)){
					if(*(repeat+i) == new[i]){
						i++;
					}
					else{
						find = 0;
						break;
					}
				}
				if(repeat+i == end) find = 1;
			}
			else{
				find = 0;
				break;
			}
			first ++;
		}

		if(find == 1){
			strcat(full, contact+i);
		}
		else{
			strcat(full, new);
		}

		end = &( full[strlen(full)] );
	}

	printf("%s\n", full);
	return 0;
}