#include <stdio.h>

int lcm(int a, int b);
int gcd(int a, int b);

int main(){
	int num1, num2;
	
	scanf("%d", &num1);
	while(scanf("%d", &num2) != EOF){
		num1 = lcm(num1, num2);
	}
	
	printf("%d", num1);
	return 0;
}

int gcd(int a, int b){
	int temp;
	if(b>a){
		temp = a;
		a = b;
		b = temp;
	}
	if(b==0){
		b=a;
	}
	
	while(a % b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	
	return b;
}

int lcm(int a, int b){
	return a*b/gcd(a,b); 
}