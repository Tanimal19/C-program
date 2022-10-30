#include <stdio.h>
#define pi 3.1415926 

int main(){
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);

	double area = c*c*pi*0.75;

	if(c-a > 0){
		area += (c-a)*(c-a)*pi*0.25;
	}

	if(c-b > 0){
		area += (c-b)*(c-b)*pi*0.25;
	}

	printf("%lf", area);
	return 0;
}