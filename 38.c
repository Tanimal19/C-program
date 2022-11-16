#include <stdio.h>

int craft(int D, int ap, int bp, int cp, int am, int bm, int cm, int maxa, int maxb, int maxc, int A, int B, int C){

	if(D == 0) return 1;

	if(D > 0){
		if(ap > 0){
			ap--;
			D -= A;
			printf("-A\n");
		}
		else{
			if(bp > 0){
				bp--;
				D -= B;
				printf("-B\n");
			}
			else{
				if(cp > 0){
					cp--;
					D -= C;
					printf("-C\n");
				}
				else{
					return 0;
				}
			}
		}
		printf("%d\n", D);
		return craft(D, ap, bp, cp, am, bm, cm, maxa, maxb, maxc, A, B, C);
	}
	else{
		if(am <= maxa){
			am++;
			D += A;
			printf("+A\n");
		}
		else{
			if(bm <= maxb){
				bm++;
				D += B;
				printf("+B\n");
			}
			else{
				if(cm <= maxb){
					cm++;
					D += C;
					printf("+C\n");
				}
				else{
					return 0;
				}
			}
		}
		printf("%d\n", D);
		return craft(D, ap, bp, cp, am, bm, cm, maxa, maxb, maxc, A, B, C);
	}

}

int main(){
	int n;
	scanf("%d", &n);
	int a, b ,c;
	int A, B ,C;
	int D;
	for(int i=0 ; i<n ; i++){
		scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
		printf("%s\n", craft(D, a, b, c, 0, 0, 0, a, b, c, A, B, C) ? "yes":"no");
	}
	return 0;
}