#include <stdio.h>
#include <ctype.h>

int main(){
	int w, h;
	scanf("%d%d", &w, &h);
	char one, zero;
	scanf("\n%c %c", &one, &zero);
	
	int size = (w*h / 32) + 1;
	unsigned int num[size];
	for(int i=0 ; i<size ; i++)
		scanf("%d", &num[i]);
	
	int count = 31, k = 0;
	for(int i=0 ; i<h ; i++){
		for(int j=0 ; j<w ; j++){
			printf("%c", ((num[k] & (1 << count)) != 0) ? one : zero);
			
			if(count <= 0){
				k++;
				count = 31;
			}
			else{
				count --;
			}
		}
		printf("\n");
	}
	
	return 0;
}