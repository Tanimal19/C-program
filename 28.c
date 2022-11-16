#include <stdio.h>

int square(int i, int sum){
	if(i==1){
		return sum + 1;
	}
	else{
		sum += i*i;
		return square(i-1, sum);
	}

}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", square(n, 0));
	return 0;
}