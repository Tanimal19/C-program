#include "value.h"

int value(int type, int width, int height, int length){
	int unit;
	switch(type){
		case 79:	//gold
			unit = 30;
			break;
		case 47:	//silver
			unit = 10;
			break;
		case 29:	//copper
			unit = 4;
			break;
		case 82:	//lead
			unit = 5;
			break;
		case 26:	//iron
			unit = 3;
			break;
		case 22:	//titanium
			unit = 9;
			break;
		default:
			return -1;
	}
	
	int dimension;
	if(width <= 0 || height <= 0 || length <= 0){
		return -2;
	}
	else{
		// gcd
		int temp;
		int a = width, b = height, c = length;
		if(b>a){
			temp = a;
			a = b;
			b = temp;
		}
		while(a % b != 0){
			temp = a % b;
			a = b;
			b = temp;
		}

		if(b>c){
			temp = c;
			c = b;
			b = temp;
		}
		while(c % b != 0){
			temp = c % b;
			c = b;
			b = temp;
		}

		dimension = b;
	}

	//calculate value
	int maxv = 0;
	int i;
	int v;
	for(i=1 ; i<=dimension ; i++){
		if(dimension % i == 0){
			v = (dimension*dimension*dimension)
				* (width*height*length)
				* unit;
			if(v >= maxv){
				maxv = v;
			}
		}
	}
	return maxv;
}
