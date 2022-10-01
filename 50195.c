#include <stdio.h>

int main(){
	int n;
	int i=0;
	int one=0, two=0, thr=0;
	int dis1, dis2, dis3;
	int loc1a, loc1b, loc2a, loc2b, loc3a, loc3b;
	int loc1ma, loc1mb, loc2ma, loc2mb, loc3ma, loc3mb;
	int pre1=0, pre2=0, pre3=0;
	int max1 = 0, secmax1 = 0;
	int max2 = 0, secmax2 = 0;
	int max3 = 0, secmax3 = 0;

	while(scanf("%d", &n) != EOF){
		switch(n){
			case 1:
				if(one > 0){
					dis1 = i-pre1;
					if(dis1 >= max1){
						if((max1 > secmax1)&&(dis1 > max1)){
							secmax1 = max1;
							loc1a = loc1ma;
							loc1b = loc1mb;
						}
						max1 = dis1;
						loc1ma = pre1;
						loc1mb = i;
					}
					else{
						if(dis1 >= secmax1){
							secmax1 = dis1;
							loc1a = pre1;
							loc1b = i;
						}
					}
				}
				pre1 = i;
				one++;
				break;

			case 2:
				if(two > 0){
					dis2 = i-pre2;
					if(dis2 >= max2){
						if((max2 > secmax2)&&(dis2 > max2)){
							secmax2 = max2;
							loc2a = loc2ma;
							loc2b = loc2mb;
						}
						max2 = dis2;
						loc2ma = pre2;
						loc2mb = i;
					}
					else{
						if(dis2 >= secmax2){
							secmax2 = dis2;
							loc2a = pre2;
							loc2b = i;
						}
					}
				}
				pre2 = i;
				two++;
				break;

			case 3:	
				if(thr > 0){
					dis3 = i-pre3;
					if(dis3 >= max3){
						if((max3 > secmax3)&&(dis3 > max3)){
							secmax3 = max3;
							loc3a = loc3ma;
							loc3b = loc3mb;
						}
						max3 = dis3;
						loc3ma = pre3;
						loc3mb = i;
					}
					else{
						if(dis3 >= secmax3){
							secmax3 = dis3;
							loc3a = pre3;
							loc3b = i;
						}
					}
				}
				pre3 = i;
				thr++;
				break;
		}
		i++;
	}
	printf("%d %d %d\n", secmax1, loc1a, loc1b);
	printf("%d %d %d\n", secmax2, loc2a, loc2b);
	printf("%d %d %d\n", secmax3, loc3a, loc3b);

	return 0;
}


