#include <stdio.h>
int evaluate_f(int *iptr[], int n, int *index){
  int i;
  int max = *iptr[0] * 4 - *(iptr[0]+1) * 6;
  *index = 0;
  for(i=1 ; i<n ; i++){
    int value = *iptr[i] * 4 - *(iptr[i]+1) * 6;
    if(value > max){
      max = value;
      *index = i;
    }
  }
  return max;
}
 
int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}