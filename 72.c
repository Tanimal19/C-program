#include <stdio.h>
void fill_array(int *ptr[], int n){
  int i = 0;
  int len = ptr[n-1] - ptr[0];
  while(i <= len){
    *(ptr[0] + i) = 0;
    i++;
  }
  for(i=0 ; i<n ; i++){
    *ptr[i] = i;
  }
  int *begin = ptr[0], *now, *end;

  while(begin != ptr[n-1]){
    now = begin+1;
    while(*now == 0){
      now++;
    }
    end = now;
    int value = *begin + *now;   
    now--;
    while(now != begin){  
      *now = value;
      now--;
    }
    begin = end;
  }
}
int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}