#include <stdio.h>

int main(){
	int n, i;
	int ans=1;
	scanf("%d%d", &n, &i);
	for(int k=1;k<=i;k++){
		ans=ans*n;
	}
	printf("%d", ans);
	return 0;
}