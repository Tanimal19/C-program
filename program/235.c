#include <stdio.h>

int numadd(int num1, int deno1, int num2, int deno2){
	num1 *= deno2;
	num2 *= deno1;
	return num1 + num2;
}

int gcd(int a, int b){
	int temp;
	if(b>a){
		temp = a;
		a = b;
		b = temp;
	}
	if(b==0){
		b=a;
	}
	
	while(a % b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	
	return b;
}

int main(){
	int row;
	scanf("%d", &row);

	int n = row*(row+1)/2;
	int left[n], right[n];
	int d[n];
	int i;
	int g;
	for(i=0;i<n;i++){
		scanf("%d %d", &left[i], &right[i]);
		g = gcd(left[i], right[i]);
		left[i] /= g;
		right[i] /= g;
		d[i] = left[i] + right[i];
	}

	// 上一排、下一排
	int pin1[row+1], d1[row];
	int pin2[row+1], d2[row];
	for(i=0;i<row+1;i++){
		pin1[i] = 1;
		d1[i] = 1;
		pin2[i] = 1;
		d2[i] = 1;
	}

	int j;
	int k = 0;
	int a1, b1, a2, b2;
	for(i=0;i<row;i++){
		k += i;
		for(j=0;j<=i+1;j++){
			if(j==0){
				pin2[j] = pin1[j] * left[k+j];
				d2[j] = d1[j] * d[k+j];
			}
			else if(j==i+1){
				pin2[j] = pin1[j-1] * right[k+j-1];
				d2[j] = d1[j-1] * d[k+j-1];
			}
			else{
				a1 = pin1[j] * left[k+j];
				b1 = d1[j] * d[k+j];
				g = gcd(a1,b1);
				a1 /= g;
				b1 /= g;

				a2 = pin1[j-1] * right[k+j-1];
				b2 = d1[j-1] * d[k+j-1];
				g = gcd(a2,b2);
				a2 /= g;
				b2 /= g;
				
				pin2[j] = numadd(a1, b1, a2, b2);
				d2[j] = b1 * b2;
			}
		}

		for(j=0;j<=i+1;j++){
			pin1[j] = pin2[j] / gcd(pin2[j], d2[j]);
			d1[j] = d2[j] / gcd(pin2[j], d2[j]);
			if(pin1[j] == 0) d1[j] = 1;
		}
	}
	
	for(i=0;i<row+1;i++){
		printf("%d/%d\n", pin1[i], d1[i]);
	}

	return 0;
}
