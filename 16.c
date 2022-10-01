#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int num[n];

	for(int i=0;i<n;i++){
		scanf("%d", &num[i]);
	}

	int odd[n];
	int even[n];
	int j=0, k=0;
	for(int i=0;i<n;i++){
		if(num[i]%2==1){
			odd[j]=num[i];
			j++;
		}
		else{
			even[k]=num[i];
			k++;
		}
	}

	for(int i=0;i<j;i++){
		if(i==j-1){
			printf("%d\n", odd[i]);
		}
		else{
			printf("%d ", odd[i]);
		}
	}

	for(int i=0;i<k;i++){
		
		if(i==k-1){
			printf("%d", even[i]);
		}
		else{
			printf("%d ", even[i]);
		}
	}
	return 0;
}