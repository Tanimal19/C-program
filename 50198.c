#include <stdio.h>

int main(){
	int a, b, x;
	int count = 0;
	int ans[1000];
	
	while(scanf("%d%d%d", &a, &b, &x) != EOF){
		int number = 3;
		while(number > 2){
			int i = 0;
			int digit[100];
			int test = x;
			number = 1;

			// 判斷包含幾種數字
			while(test != 0){
				digit[i] = test%10;
				test /= 10;
				int j = 0;
				while(digit[i]!=digit[j]){
					if(j == i-1) number++;
					j++;
				}
				i++;
			}
			
			#ifdef DEBUG
			printf("number:%d\n", number);
			#endif

			if(number > 2) x = (a*x)%b;
		}
		ans[count] = x;
		count++;
	}
	for(int i=0;i<count;i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}