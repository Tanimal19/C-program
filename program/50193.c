# include <stdio.h>

int main(){
	int time[1000];
	int n=0;
	while(scanf("%d", &time[n]) != EOF){ 
		n++;
	}
	
	for(int i=0;i<n;i++){
		time[i] = (time[i]/10000)*3600 + (time[i]/100 - (time[i]/10000)*100)*60 + time[i]%100;
	}

	int dif[1000];
	for(int i=0;i<n-1;i++){
		dif[i] = time[i+1]-time[i];
		dif[i] = dif[i]<0 ? -dif[i]:dif[i];	
	}
	int final = dif[0];
	for(int i=0;i<n-1;i++){
		if(dif[i]<=final){
			final = dif[i];
		}
	}
	printf("%d", final);

	return 0;
}