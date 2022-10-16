#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	int a[n];

	int i;
	int num[100];
	for(i=0;i<100;i++){
		num[i] = -1;
	}

	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	int k;
	for(i=0;i<n;i++){
		k = a[i] - 1;
		if(num[k] != -1){
			printf("%d %d %d\n", i, num[k], a[i]);
			num[k] = -1;
		}
		else{
			num[k] = i;
			printf("%d\n", i);
		}
	}


	return 0;
}