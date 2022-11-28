#include <stdio.h>
#include <string.h>

int main(){
	char c;
	int num = 0;
	int sum = 0;
	int last = 1;

	while(scanf("%c", &c) != EOF){
		
		switch(c){
			case '!':
				num = num*10 + 1;
				break;
			case '@':
				num = num*10 + 2;
				break;
			case '#':
				num = num*10 + 3;
				break;
			case '$':
				num = num*10 + 4;
				break;
			case '%':
				num = num*10 + 5;
				break;
			case '^':
				num = num*10 + 6;
				break;
			case '&':
				num = num*10 + 7;
				break;
			case '(':
				num = num*10 + 9;
				break;
			case ')':
				num = num*10 + 0;
				break;
			case '+':
				num *= last;
				sum += num;
				num = 0;
				last = 1;
				break;
			case '*':
				last *= num;
				num = 0; 
			default:
				break;
		}	
	}
	num *= last;
	sum += num;
	printf("%d", sum);
	return 0;
}