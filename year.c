#include <stdio.h>

int main(){
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year;
	scanf("%d", &year);
	if(year%4 == 0 && (year%100 != 0 || year%400 == 0)){
		month[1] = 29;
	}
	printf("\n%d\n", month[1]);
	return 0;
}