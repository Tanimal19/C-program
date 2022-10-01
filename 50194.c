#include <stdio.h>

int main(){
	int k, l;
	scanf("%d", &k);
	scanf("%d", &l);

    int n[1000];
    int i = 0;
   	while(i != -1){
   		scanf("%d", &n[i]);
   		if(n[i] == 0){
   			break;
   		}
   		i++;
   	}
   	
   	int time = i;
   	int limit = l;
   	int length[1000];
   	
    for(i=0;i<time;i++){
		// 計算位數    	
    	int t = n[i];
    	while(t != 0){
        	t /= 10;
        	++length[i];
    	}

    	if((n[i]%k) * length[i] <= l){
    		for(int j=0;j<(n[i]%k);j++){
    			printf("%d", n[i]);
    			l = l - length[i];
    		}
    	}
    	else{
    		if((n[i]%k) * length[i] <= limit){
    			printf("\n");
    			l = limit;
    			for(int j=0;j<(n[i]%k);j++){
    				printf("%d", n[i]);
    				l = l - length[i];
    			}
    		}
    	}
    	#ifdef DEBUG
    	printf("\nL:%d\n", l);
    	#endif
    }
    return 0;
}