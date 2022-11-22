#include <stdio.h>

int form[4][3][4] = {
  // type			x				y
	{{1, 4, 1, 2}, {0, -1, -1, 1}, {0, 1, -1, -1}},
	{{2, 1, 2, 3}, {0, -1, 1, 1}, {0, -1, -1, 1}},
	{{3, 4, 3, 2}, {0, -1, 1, 1}, {0, 1, 1, -1}},
	{{4, 1, 4, 3}, {0, -1, -1, 1}, {0 , -1, 1, 1}}
};

void puzzle(int l, int m, int x, int y, int type){
	if(l==2){
		printf("%d %d %d\n", type, x, y);
		return;
	}

	for(int i=0 ; i<4 ; i++){
		puzzle(l/2, l/4, x + (form[type-1][1][i] * l/4), y + (form[type-1][2][i] * l/4), form[type-1][0][i]);
	}
	int w = l/2 - m;
	if(w > 0){
		puzzle(l/2, m, x+l/4, y+l/4, 1);
	}
	return;
}

int main(){
	int l, m;
	scanf("%d%d", &l, &m);

	puzzle(l, m, l/2, l/2, 1);
	return 0;
}