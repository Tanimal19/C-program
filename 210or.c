#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 80

typedef struct data{
	char lastname[STRLEN];
	char firstname[STRLEN];
	char ID[STRLEN];
	int salary;
	int age;
} Data;

int n;
Data a[50];
char keyword[5][STRLEN] = {"lastname", "firstname", "ID", "salary", "age"};
char operator[4][5] = {"==", "!=", ">", "<"};

int condition(int find, int ope, char *start, int i){
	char str[STRLEN];
	int num;

	switch(find){
		case 1:
			strcpy(str, a[i].lastname);
			break;
		case 2:
			strcpy(str, a[i].firstname);
			break;
		case 3:
			strcpy(str, a[i].ID);
			break;
		case 4:
			num = a[i].salary;
			break;
		case 5: 
			num - a[i].age;
			break;
	}

	switch(ope){
		case 0: /* == */
			return strcmp(str, start) == 0 ? 1:0;
		case 1: /* != */
			return strcmp(str, start) != 0 ? 1:0;
		case 2: /* > */
			return num > atoi(start) ? 1 : 0;
		case 3: /* < */
			return num < atoi(start) ? 1 : 0;
	}
}

void printfield(int field, int i){
	switch(field){
		case 1:
			printf("%s", a[i].lastname);
			break;
		case 2:
			printf("%s", a[i].firstname);
			break;
		case 3:
			printf("%s", a[i].ID);
			break;
		case 4:
			printf("%d", a[i].salary);
			break;
		case 5:
			printf("%d", a[i].age);
			break;
	}
}

void getorder(){
	char order[1000];
	scanf("%s", order);
	char *start = strtok(order, " ");
	int field[8], f = 0;

	int firsthalf = 0, secondhalf = 0;
	int find, ope;

	while(start != NULL){
		if(firsthalf == 1){
			for(int i=0 ; i<5 ; i++){
				if(strcmp(start, keyword[i]) == 0){
					field[f] = i+1;
					f++;
				}
			}
		}

		switch(secondhalf){
			case 1:
				for(int i=0 ; i<5 ; i++)
					if(strcmp(start, keyword[i]) == 0)
						find = i+1;
				secondhalf++;
				break;
			case 2:
				for(int i=0 ; i<4 ; i++)
					if(strcmp(start, operator[i]) == 0)
						ope = i;
				secondhalf++;
				break;
			case 3:
				for(int i=0 ; i<n ; i++){
					if(condition(find, ope, start, i)){
						for(int j=0 ; j<f ; j++){
							printfield(field[j], i);
							printf("%c", j==f-1 ? '\n':' ');
						}
					}
				}
				secondhalf++;
				break;
		}
	
		if(strcmp(start, "select") == 0) firsthalf = 1;
		if(strcmp(start, "where") == 0) secondhalf = 1;
		start = strtok(NULL, " ");
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		scanf("%s %s %s %d %d\n", &a[i].lastname, &a[i].firstname, &a[i].ID, &a[i].salary, &a[i].age);

	int s;
	scanf("%d", &s);
	for(int i=0 ; i<s ; i++){
		getorder();
	}
	return 0;
}