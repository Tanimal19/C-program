#include <stdio.h>

int main(){
	int a=0, b=0, c=0;
	int time;
	scanf("%d", &time);
	for(int i=0;i<time;i++){
		int n;
		scanf("%d", &n);
		switch(n%3){
			case 0:
				a++;
				break;
			case 1:
				b++;
				break;
			case 2:
				c++;
				break;
		}
	}
	printf("%d %d %d", a, b, c);
}