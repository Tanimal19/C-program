#include <stdio.h>
#include <string.h>
#define WORDSIZE 51

char word[20][WORDSIZE];
int n;

int find(int i, int cost, int letter){
	if(letter == 0) return cost;
	if(i==n) return 26000;

	int notchoose = find(i+1, cost, letter);

	int len = strlen(word[i]);
	for(int j=0 ; j<len ; j++){
		cost += (word[i][j]-96);
		int test = 1 << (word[i][j]-97);
		letter &= ~test;
	}

	int choose = find(i+1, cost, letter);

	return (notchoose < choose) ? notchoose : choose;
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i=0 ; i<n ; i++)
			scanf("%s", word[i]);

		printf("%d\n", find(0, 0, 67108863));
	}
	return 0;
}