#include <stdio.h>

int num[10], n; 

void print(int p[]){
	for(int i=0 ; i<n ; i++)
		printf("%d%c", p[i], i==n-1 ? '\n':' ');
	return;
}

void permutation(int head, int p[]){
	if(head==n){
		print(p);
		return;
	}
	for(int i=0 ; i<n-head ; i++){
		int repeat = 0;
		for(int j=0 ; j<head+1 ; j++){
			if(num[head+i] == p[j]){
				repeat = 1;
			}
		}
		
		p[head] = num[head+i];
		permutation(head+1, p);
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		scanf("%d", &num[i]);
	
	int p[n];
	permutation(0, p);
	return 0;
}