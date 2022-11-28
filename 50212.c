#include <stdio.h>

unsigned int function(unsigned int c, int n){
	int bit = 0;
	if(n==1) return c;

	for(int i=0 ; i<n ; i++){
		if((c>>i) & 1 == 1) bit++;
	}

	int l = 32 - n/2;
	
	unsigned int right = function(c >> n/2, n/2);
	unsigned int left = function((c << l) >> l, n/2);

	if(bit % 2 == 1){
		return (left << n/2) + right;
	}
	return (right << n/2) + left;
}

int main(){
	unsigned int c;
	scanf("%u", &c);
	printf("%u", function(c, 32));
	return 0;
}