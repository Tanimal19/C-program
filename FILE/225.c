#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXN 10000

typedef struct person {
    unsigned int id;
    char name[32];
} Person;

typedef struct friends {
    unsigned id1;
    unsigned id2;
} Friends;

int main(){
	FILE *fin = fopen("friends", "rb");
	assert(fin != NULL);

	int p;
	fread(&p, sizeof(int), 1, fin);
	Person person[MAXN];
	for(int i=0 ; i<p ; i++){
		fread(&(person[i]), sizeof(Person), 1, fin);
	}

	int f;
	fread(&f, sizeof(int), 1, fin);
	Friends friend[MAXN];
	for(int i=0 ; i<f ; i++){
		fread(&(friend[i]), sizeof(Friends), 1, fin);
	}

	fclose(fin);

	char n1[32], n2[32];
	
	scanf("%s", n1);
	while(strcmp(n1, "end") != 0){
		scanf("%s", n2);

		int ID1 = -1, ID2 = -1;
		for(int i=0 ; i<p ; i++){
			if(strcmp(n1, person[i].name) == 0) ID1 = person[i].id;
			if(strcmp(n2, person[i].name) == 0) ID2 = person[i].id;
			if((ID1 != -1) && (ID2 != -1)) break;
		}

		int find = 0;
		for(int i=0 ; i<f ; i++){
			if((ID1 == friend[i].id1 && ID2 == friend[i].id2) || (ID2 == friend[i].id1 && ID1 == friend[i].id2)){
				find = 1;
				break;
			}
		}

		printf("%s\n", find==1 ? "yes":"no");
		
		scanf("%s", n1);
	}
	return 0;
}