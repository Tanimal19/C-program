#include <stdio.h>
#include <string.h>
#define STRLEN 1000000

typedef struct info{
	int ivalid;
	int ivalue;
	char *inow;
}Info;

Info expression(int valid, int value, char *now){

	while((*now != ')')){
		
		if(*now == '(' && *(now+1) == '('){
			value = expression(0, 0, now+1).ivalue;
			now = expression(0, 0, now+1).inow;
		}
		now++;

		switch(*now){
			case '+':
				value += expression(0, 0, now+1).ivalue;
				now = expression(0, 0, now+1).inow;
				break;
			case '-':
				value -= expression(0, 0, now+1).ivalue;
				now = expression(0, 0, now+1).inow;
				break;
			case '*':
				value *= expression(0, 0, now+1).ivalue;
				now = expression(0, 0, now+1).inow;
				break;
			case '/':
				value /= expression(0, 0, now+1).ivalue;
				now = expression(0, 0, now+1).inow;
				break;
			default:
				value = value*10 + (*now-48);
		}
		
		printf("value %d now %p\n", value, now);
	}

	Info i = { 0, value, now };
	return i;
}

int main(){
	char str[STRLEN];
	while(scanf("%s", str) != EOF){
		Info i = expression(0, 0, &str[0]);
		printf("%d\n", i.ivalue);
	}
	return 0;
}