#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 35

typedef struct variable{
	char label[MAXLEN];
	int value;
}Variable;

typedef struct info{
	int sum;
	int end;
}Info;

char input[1000][MAXLEN];

Variable variable[50];
int var = 0;

int isvariable(char c){
	return (c != '(' && c != ')' &&
			c != '+' && c != '-' && c != '*' && c != '/' &&
			!(c >= '0' && c <= '9'));
}

int findvariable(char *p){
	for(int i=0 ; i<var ; i++){
		if(strcmp(variable[i].label , p) == 0){
			return i;
		}
	}
	return -1;
}

Info compute(int now){
	Info expression;
	if(strcmp(input[now], "(") == 0){

		printf("left %d\n", now);
		Info left = compute(now+2);
		printf("right %d\n", now);
		Info right = compute(left.end);
		expression.end = right.end;

		printf("%d %d %s\n", left.sum, right.sum, input[now+1]);

		if(strcmp(input[now+1], "+") == 0){
			expression.sum = left.sum + right.sum;
		}
		else if(strcmp(input[now+1], "-") == 0){
			expression.sum = left.sum - right.sum;
		}
		else if(strcmp(input[now+1], "*") == 0){
			expression.sum = left.sum * right.sum;
		}
		else if(strcmp(input[now+1], "/") == 0){
			expression.sum = left.sum / right.sum;
		}
		printf("ope now:%d sum:%d\n", now+1, expression.sum);

		return expression;
	}
	else{
		if(input[now][0] >= '0' && input[now][0] <= '9'){
			expression.sum = atoi(input[now]);
			printf("num now:%d sum:%d\n", now, expression.sum);
			expression.end = now+1;
			return expression;
		}
		else{
			expression.sum = variable[ findvariable(input[now]) ].value;
			printf("var now:%d sum:%d\n", now, expression.sum);
			expression.end = now+1;
			return expression;
		}
	}
}

int main(){
	
	int i = 0, set = 0;
	do{
		scanf("%s", &input[i]);
		if(strcmp(input[i], "(") == 0) set ++;
		if(strcmp(input[i], ")") == 0) set --;

		if(isvariable(input[i][0])){
			if(findvariable(input[i]) == -1){
				strcpy(variable[var].label , input[i]);
				var++;
			}
		}

		i++;
	}while(set != 0);

	char v[MAXLEN];
	int value, id;
	for(int i=0 ; i<var ; i++){
		scanf("%s = %d", v, &value);
		id = findvariable(v);
		variable[id].value = value;
	}

	Info final = compute(0);
	printf("%d", final.sum);
	return 0;
}