#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int arr[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	int m;
	scanf("%d", &m);

	int ans[m];
	for(i=0;i<m;i++){
		ans[i]=0;
	}
	
	for(i=0;i<n;i++){
		ans[arr[i]%m]++; 
	}

	for(i=0;i<m;i++){
		printf("%d\n", ans[i]); 
	}
	
	return 0;
}