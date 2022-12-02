#include <stdio.h>
#include <string.h>
#define SIZE 50

int friend[SIZE][2];
int n;

typedef struct subset{
	int in[SIZE];
	int person[64];
	int p;
}Subset;

Subset findfriend(int now, int m, Subset cover){

	if(m == 0) return cover;
	if(now == n){
		cover.p = n;
		return cover;
	}

	Subset notchoose = findfriend(now+1, m, cover);

	int i2 = 0, m2 = m;
	for(int i=0 ; i<m ; i++){
		if(friend[cover.in[i]][0] == now || friend[cover.in[i]][1] == now){
			m2--;
		}
		else{
			cover.in[i2] = i;
			i2++;
		}
	}
	cover.person[cover.p] = now;
	cover.p ++;
	
	Subset choose = findfriend(now+1, m2, cover);

	return notchoose.p < choose.p ? notchoose : choose;
}

int main(){
	int m;
	scanf("%d%d", &n, &m);

	Subset cover;
	for(int i=0 ; i<m ; i++){
		scanf("%d%d", &friend[i][0], &friend[i][1]);
		cover.in[i] = i;
	}

	cover.p = 0;
	cover = findfriend(0, m, cover);
	for(int i=0 ; i<cover.p ; i++)
		printf("%d\n", cover.person[i]);

	return 0;
}
