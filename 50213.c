#include <stdio.h>
#include <stdlib.h>

int *sort(int *arr, int len){

	for(int i=0 ; i<len ; i++)
		printf("%d%c", arr[i], i==len-1 ? '\n':' ');

	if(len == 1) return arr;

	int left = len/2;
	int right = len - left;

	int *Larr = sort(arr, left);
	int L[left];
	for(int i=0 ; i<left ; i++)
		L[i] = *(Larr+i);

	Larr = &L[0];

	int *Rarr = sort(arr+left, right);
	int R[right];
	for(int i=0 ; i<right ; i++)
		R[i] = *(Rarr+i);

	Rarr = &R[0];

	int n[len];
	for(int i=0 ; i<len ; i++){
		if(*Larr <= *Rarr){
			n[i] = *Larr;
			Larr++;
			left--;
		}
		else{
			n[i] = *Rarr;
			Rarr++;
			right--;
		}

		if(left <= 0){
			i++;
			while(i<len){
				n[i] = *Rarr;
				i++;
				Rarr++;
			}
			break;
		}
		if(right <= 0){
			i++;
			while(i<len){
				n[i] = *Larr;
				i++;
				Larr++;
			}
			break;
		}
	}

	for(int i=0 ; i<len ; i++)
		printf("%d%c", n[i], i==len-1 ? '\n':' ');

	arr = &n[0];
	return arr;
}

int main(){
	int n[100000];
	int i=0;
	while(scanf("%d", &n[i]) != EOF){
		i++;
	}

	sort(&n[0], i);
	
	return 0;
}