#include <stdio.h>

int main(){
	int fyear, fday;
	scanf("%d%d", &fyear, &fday);
	
	//判斷閏年給定月份天數
	int fmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(fyear%4 == 0){ 
		if(fyear%100 != 0 || fyear%400 == 0){
			fmonth[1] = 29;
		}
	}

	int n;
	scanf("%d", &n);
	int ans[n];

	int i;
	int j;
	for(i=0;i<n;i++){
		int month, day;
		scanf("%d%d", &month, &day);
		if(month>12 || month<=0){
			ans[i] = -1;
		}
		else{
			if(day>fmonth[month-1] || day<=0){
				ans[i] = -2;
			}
			else{
				for(j=0;j<month-1;j++){
					day+=fmonth[j];
				}
				ans[i] = (fday+day-1)%7;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}