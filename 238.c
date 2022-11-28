#include <stdio.h>
#define setsize 16

int findset(int *pset, int key){
	int ans = 0;
	int i = 0;
	while(*pset != -1){
		if(*pset < key){	
			ans += findset(pset+1, key-*pset);
		}
		else if(*pset == key){
			ans ++;
		}
		pset++;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	int set[setsize] = {0};
	set[n] = -1;
	int i;
	for(i=0 ; i<n ; i++)
		scanf("%d", &set[i]);
	

	int key;
	while(scanf("%d", &key) != EOF){
		int *pset = &(set[0]);
		printf("%d\n", findset(pset, key));
	}
	return 0;
}
