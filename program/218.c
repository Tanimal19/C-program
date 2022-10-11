#include <stdio.h>

int comb(int n, int k);

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	int i;
	int ans = 0;
	for(i=0;i<=m;i++){
		ans += comb(n, i);
	}

	printf("%d", ans);
	return 0;
}

int comb(int n, int k){
	int i;
	int nume=1, deno=1;
	if(n-k > n/2){
		k = n-k;
	}

	for(i=(k+1);i<=n;i++){
		nume *= i;
	}

	for(i=1;i<=(n-k);i++){
		deno *= i;
	}

	return nume/deno;
}