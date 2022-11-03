#include <stdio.h>
#include <assert.h>
 
void snake(const int *ptr_array[100][100], int m){
  const int *ptr[10000];
  int p = 0;
  int i, j;
  for(i=0 ; i<m ; i++){
    for(j=0 ; j<m ; j++){
      ptr[p] = i%2==0 ? ptr_array[i][j] : ptr_array[i][m-j-1];
      p++;
    }
  }

  const int *temp;
  for(i=m*m ; i>0 ; i--){
    for(j=0 ; j<i-1 ; j++){
      if(*ptr[j+1] < *ptr[j]){
        temp = ptr[j+1];
        ptr[j+1] = ptr[j];
        ptr[j] = temp;
      }
    }
  }

  p = 0;
  for(i=0 ; i<m ; i++){
    for(j=0 ; j<m ; j++){
      if(i%2==0){
        ptr_array[i][j] = ptr[p];
      }
      else{
        ptr_array[i][m-j-1] = ptr[p];
      }
      p++;
    }
  }
}
 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}