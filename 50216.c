#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 15

char s1[STRLEN], s2[STRLEN], s3[STRLEN];

int find(char *now1, char *now2, char *now3, int len){
	if(now1 == NULL || now2 == NULL || now3 == NULL) return len;

	if(*now1 == '\0' || *now2 == '\0' || *now3 == '\0') return len;

	int case1, case2 = -1;
	if(*now1 == *now2 && *now2 == *now3){
		case1 = find(now1+1, now2+1, now3+1, len) + 1;
	}
	else{
		case1 = find(now1+1, now2+1, now3+1, len);
		
		int same1 = find(now1, strchr(now2, *now1), strchr(now3, *now1), len);
		int same2 = find(strchr(now1, *now2), now2, strchr(now3, *now2), len);
		int same3 = find(strchr(now1, *now3), strchr(now2, *now3), now3, len);
		
		case2 = (same1 > same2) ? same1 : same2;
		case2 = (case2 > same3) ? case2 : same3;
	}

	return (case1 > case2) ? case1 : case2;
}

int main(){
	
	while(scanf("%s%s%s", s1, s2, s3) != EOF){
		char *now1 = &s1[0], *now2 = &s2[0], *now3 = &s3[0];
		printf("%d\n", find(now1, now2, now3, 0));
	}
	
	return 0;
}