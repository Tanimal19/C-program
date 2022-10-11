#include <stdio.h>

int max(int a[5][5]){
	int i, j;
	int m=0;

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
        	if(a[i][j] >= m){
        		m = a[i][j];
        	}
        }
    }
	
	return m;        
}