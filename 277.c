#include <stdio.h>
#include <string.h>

void vertical(char c, int w, int form){
	int i;
	printf(" ");
	for(i=0 ; i<w ; i++){
		printf("%c", form==1 ? c : ' ');
	}
	printf(" ");
	printf(" ");
}

void horizon(char c, int w, int form[2]){
	int i;
	printf("%c", form[0]==1 ? c : ' ');
	for(i=0 ; i<w ; i++){
		printf(" ");
	}
	printf("%c", form[1]==1 ? c : ' ');
	printf(" ");
}

void printnum(char num[10], int w, int h){
	int i, j;
	int lw = w-3;
	int lh = (h-3)/2;

	int VERFORM[3][10] = {{1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1, 0, 1, 0}};
	int UPFORM[10][2] = {{1,1}, {0,1}, {0,1}, {0,1}, {1,1}, {1,0}, {1,0}, {1,1}, {1,1}, {1,1}};
	int DOWNFORM[10][2] = {{1,1}, {0,1}, {1,0}, {0,1}, {0,1}, {0,1}, {1,1}, {0,1}, {1,1}, {0,1}};


	for(i=0 ; i<strlen(num) ; i++){
		vertical(num[i], lw, VERFORM[0][num[i]-48]);
	}
	printf("\n");	

	for(i=0 ; i<lh ; i++){
		for(j=0 ; j<strlen(num) ; j++){
			horizon(num[j], lw, UPFORM[num[j]-48]);
		}
		printf("\n");
	}

	for(i=0 ; i<strlen(num) ; i++){
		vertical(num[i], lw, VERFORM[1][num[i]-48]);
	}
	printf("\n");
	

	for(i=0 ; i<lh ; i++){
		for(j=0 ; j<strlen(num) ; j++){
			horizon(num[j], lw, DOWNFORM[num[j]-48]);
		}
		printf("\n");
	}

	for(i=0 ; i<strlen(num) ; i++){
		vertical(num[i], lw, VERFORM[2][num[i]-48]);
	}
	printf("\n");

}

int main(){
	char num[10];
	int w, h;	

	while(scanf("%s%d%d", &num, &w, &h) != EOF){
		printnum(num, w, h);
	}
	
	return 0;
}