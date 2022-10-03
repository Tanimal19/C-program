#include <stdio.h>

int main(){
	int n[100];
	int i = 0;
	while(scanf("%d", &n[i]) != EOF){
		i++;
	}

	
	int left, mid = 1, right;
	int left2, mid2, right2;
	int maxleft=i-2, maxright=i-1; 
	int len, maxlen = 0;
	while(mid < i){
		#ifdef DEBUG
		printf("mid:%d, maxlen:%d, maxleft:%d, maxright:%d\n", mid, maxlen, maxleft, maxright);
		#endif
		len = 1;
		if(n[mid]==n[mid+1]){	// if the mid number repeat
			left = mid-1;
			right = mid+2;
		}
		else{
			left = mid-1;
			right = mid+1;
		}
		// find first palindrome
		while(n[left] == n[right]){
			len = right-left+1+1;
			if(left == 0)	break;
			left--; right++;
		}

		// find second palindrome
		left++;
		right--;
		mid2 = right+1;
		while(mid2 < i){
			if(n[mid2]==n[mid2+1] && n[mid2-1] != n[mid2]){		// if the mid2 number repeat
				left2 = mid2-1;
				right2 = mid2+2;
				if(mid2==right+1) len+=1;
			}
			else{
				left2 = mid2-1;
				right2 = mid2+1;
			}
			
			while(n[left2] == n[right2]){	
				if(left2 < right+1){
					left = mid;
				}
				if(left2 <= right+1){
					len = right2-left+1;
				}
				
				if(left2 == mid+1)	break;	
				left2--; right2++;
			}
			
			#ifdef DEBUG
			printf("mid2:%d ,len:%d\n", mid2, len);
			#endif

			mid2++;
		}
		if(len >= maxlen){
			maxlen = len;
			maxleft = left;
			maxright = left+len-1;
		}

		mid++;
	}
	
	for(i=maxleft;i<maxright;i++){
		printf("%d ", n[i]);
	}
	printf("%d", n[maxright]);

	return 0;
}