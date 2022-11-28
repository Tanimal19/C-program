#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d", &n);
	n -= 1;

	double perimeter = 0;

	double a1, b1, c1, a2, b2, c2;
	scanf("%lf%lf%lf", &a1, &b1, &c1);
	scanf("%lf%lf%lf", &a2, &b2, &c2);
	double a0 = a1, b0 = b1, c0 = c1;

	double y0 = (c2 - (a2/a1)*c1) / (b2 - (a2/a1)*b1);
	double x0 = c1/a1 - (b1/a1)*y0;
	double x1 = x0, y1 = y0, x2, y2;

	for(int i=0 ; i<n ; i++){
		a1 = a2;
		b1 = b2;
		c1 = c2;
		if(i != n-1){
			scanf("%lf%lf%lf", &a2, &b2, &c2);
		}
		else{
			a2 = a0; b2 = b0; c2 = c0;
		}
		
		y2 = (c2 - (a2/a1)*c1) / (b2 - (a2/a1)*b1);
		x2 = c1/a1 - (b1/a1)*y1;

		perimeter += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
		
			
		x1 = x2;
		y1 = y2;		
	}
	perimeter += sqrt( (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1) );
	printf("%.3lf", perimeter);
	return 0;
} 