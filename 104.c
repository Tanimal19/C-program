#include <stdio.h>

int comp(int good[3][3], int type, int m[3], int use[3]){
	
	if(m[0] == 0){
		m[1] -= good[1][0] * use[0] + good[1][1] * use[1] + good[1][2] * use[2];
		m[2] -= good[2][0] * use[0] + good[2][1] * use[1] + good[2][2] * use[2];
		if(m[1] == 0 && m[2] == 0) return 1;
		return 0;
	}

	if(m[0] < 0){
		return 0;
	}

	if(m[0] > 0){
		// save original status
		int ouse[3] = {use[0], use[1], use[2]}; 
		int om[3] = {m[0], m[1], m[2]};


		// choose present material 
		m[0] -= good[0][type];
		use[type] ++;
		if(comp(good, type, m, use)) return 1;
		
		// choose next material
		type += 1;
		if(type >= 3) return 0;
		return comp(good, type, om, ouse);
	}
}

int loop(int n, int good[3][3]){ 
	if(n <= 0) return 0;

	int m[3];	//materials
	scanf("%d%d%d", &m[0], &m[1], &m[2]);
	int use[3] = {0};
	printf("%s\n", comp(good, 0, m, use) ? "yes" : "no");
	
	loop(n-1, good);
}

int main(){
	int good[3][3];
	scanf("%d%d%d", &good[0][0], &good[1][0], &good[2][0]);
	scanf("%d%d%d", &good[0][1], &good[1][1], &good[2][1]);
	scanf("%d%d%d", &good[0][2], &good[1][2], &good[2][2]);
			
	int n;
	scanf("%d", &n);
	loop(n, good);

	return 0;
}