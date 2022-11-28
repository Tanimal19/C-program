#include <stdio.h>

int cardinality(int ax, int ay, int bx, int by);
int intersection2(int ax1, int ay1, int ax2, int ay2,
					int bx1, int by1, int bx2, int by2);

int intersection3(int ax1, int ay1, int ax2, int ay2,
					int bx1, int by1, int bx2, int by2,
					int cx1, int cy1, int cx2, int cy2);

int main(){
	int ax1, ay1, ax2, ay2;
	int bx1, by1, bx2, by2;
	int cx1, cy1, cx2, cy2;

	scanf("%d%d%d%d", &ax1, &ay1, &ax2, &ay2);
	scanf("%d%d%d%d", &bx1, &by1, &bx2, &by2);
	scanf("%d%d%d%d", &cx1, &cy1, &cx2, &cy2);

	int ans =
	cardinality(ax1, ay1, ax2, ay2) +
	cardinality(bx1, by1, bx2, by2) +
	cardinality(cx1, cy1, cx2, cy2) -
	intersection2(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) -
	intersection2(bx1, by1, bx2, by2, cx1, cy1, cx2, cy2) -
	intersection2(ax1, ay1, ax2, ay2, cx1, cy1, cx2, cy2) +
	intersection3(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, cx1, cy1, cx2, cy2);

	printf("%d", ans);
	return 0;
}

int cardinality(int ax, int ay, int bx, int by){
	return (bx-ax)*(by-ay);
}

int intersection2(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
	if((bx1 >= ax2) || (bx2 <= ax1) || (by1 >= ay2) || (by2 <= ay1)){
		return 0;
	}
	else{
		int cx1 = ax1>bx1 ? ax1:bx1;
		int cy1 = ay1>by1 ? ay1:by1;
		int cx2 = ax2>bx2 ? bx2:ax2;
		int cy2 = ay2>by2 ? by2:ay2;
		return cardinality(cx1, cy1, cx2, cy2);
	}
	
}

int intersection3(int ax1, int ay1, int ax2, int ay2,  int bx1, int by1, int bx2, int by2, int cx1, int cy1, int cx2, int cy2){
	if((bx1 >= ax2) || (bx2 <= ax1) || (by1 >= ay2) || (by2 <= ay1)){
		return 0;
	}
	else{
		int dx1 = ax1>bx1 ? ax1:bx1;
		int dy1 = ay1>by1 ? ay1:by1;
		int dx2 = ax2>bx2 ? bx2:ax2;
		int dy2 = ay2>by2 ? by2:ay2;
		return intersection2(dx1, dy1, dx2, dy2, cx1, cy1, cx2, cy2);
	}
}