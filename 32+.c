#include <stdio.h>

int main(){
	int n[100];
	int i = 0;
	while(scanf("%d", &n[i]) != EOF){
		i++;
	}

	int mid1=0, mid2;
	int left1, right1;
	int len1;
	while(mid1<i){
		
		if(n[mid1]==n[mid1+1] && n[mid1]!=n[mid1-1]){	// if the mid1 number repeat
			left1 = mid1-1;
			right1 = mid1+2;
			len1 = 2;
		}
		else{
			left1 = mid1-1;
			right1 = mid1+1;
			len1 = 1;
		}

		while(n[mid1-1] == p[mid1+1]){
			len1 += 2;
			if(left1 <= 0){
				break;
			}
			left1--; right1++;
		}

		

	}

	return 0;
}