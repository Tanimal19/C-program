#include <stdio.h>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	int i, j;
	int num;
	int sum[m], max[m], min[m];
	int time[m];

	for(i=0;i<m;i++){
		time[i] = 0;
		sum[i] = 0;
		max[i] = 0;
		min[i] = 10000;
	}
	
	for(i=0;i<n;i++){
		scanf("%d", &num);
		j = num%m;
	
		sum[j] += num;

		if(num >= max[j]){
			max[j] = num;
		}

		if(num <= min[j]){
			min[j] = num;
		}

		time[j]++;
	}
	
	for(i=0;i<m;i++){
		printf("%d %d %d\n", sum[i], max[i], min[i]);
	}

	return 0;
}	