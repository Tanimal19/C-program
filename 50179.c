#include <stdio.h>
#include <string.h>

typedef struct outfile{
	char name[50];
	int length;
} Outfile ;

int main(){
	char in[50], prefix[50];
	int n;
	scanf("%s", in);
	scanf("%d", &n);
	scanf("%s", prefix);

	Outfile out[10];
	char index[10][3] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

	for(int i=0 ; i<n ; i++){
		strcpy(out[i].name , prefix);
		strcat(out[i].name , index[i]);

		FILE *reset = fopen(out[i].name, "w");
		fclose(reset);

		out[i].length = 0;
	}

	FILE *fin = fopen(in, "rb");
	FILE *fout;

	int now = 0;
	unsigned char num;
	while(fread(&num, sizeof(unsigned char), 1, fin) > 0){
		if(num == 255){
			for(int i=0 ; i<n ; i++){
				if(out[i].length < out[now].length){
					now = i;
				}
				else if(out[i].length == out[now].length && i < now){
					now = i;
				}
			}
		}
		else{
			// printf("add into file %s\n", out[now].name);
			fout = fopen(out[now].name , "ab");
			fwrite(&num, sizeof(unsigned char), 1, fout);
			out[now].length ++;
			fclose(fout);
		}
	}

	fclose(fin);
	return 0;
}