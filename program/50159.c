#include <stdio.h>

int main(){
	int a, b;
	
	int d = 0;
	int r = 0;
	int flag = 0;

	int end1 = 0, end2;
	int len1 = 0, len2;
	int maxlen = 0;
	int maxleft = 0;
	int maxend = 0;
	
	int i=0;
	while(scanf("%d", &a) != EOF){
		if(i>=1){
			if(a < b){		//down	
				if(r == 1){
					end2 = i-1;
					flag = 1;
				}
				d=1;			
				r=0;
			}
			else{			//rise
				if(d == 1){
					end2 = i-1;
					flag = 1;
				}
				r=1;			
				d=0;
			}

			if(flag == 1){
				len2 = end2 - end1 + 1;
				if((len2 + len1 - 1) > maxlen){
					maxlen = (len2 + len1 - 1);
					maxleft = len1;
					maxend = end2;
				}
				else if((len2 + len1 - 1) == maxlen){
					if(len1 > maxleft){
						maxlen = (len2 + len1 - 1);
						maxleft = len1;
						maxend = end2;
					}
				}

				end1 = end2;
				len1 = len2;
				flag = 0;
			}
			
		}

		i++;
		b = a;
	}

	if(end1 == 0){
		printf("0");
	}
	else{
		end2 = i-1;
		len2 = end2 - end1 + 1;
		if((len2 + len1 - 1) > maxlen){
			maxlen = (len2 + len1 - 1);
			maxleft = len1;
			maxend = end2;
		}
		else if((len2 + len1 - 1) == maxlen){
			if(len1 > maxleft){
				maxlen = (len2 + len1 - 1);
				maxleft = len1;
				maxend = end2;
			}
		}
		printf("%d %d", maxlen, (maxend - maxlen + 2));
	}
	
	return 0;
}