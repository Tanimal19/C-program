#include <stdio.h>
void prepare_array(int buffer[], int *array[], int row, int column[]){
  int i;
  array[0] = &(buffer[0]);
  for(i=1 ; i<row ; i++){
    array[i] = array[i-1] + column[i-1];
  }
}
 
int main() {
  int row = 4;
  int column[4] = {10, 20, 30, 10};
  int *array[50];
  int buffer[10000];
  prepare_array(buffer, array, row, column);
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < column[i]; j++){
      array[i][j] = i * 100 + j;
      printf("%d\n", array[i][j]);
    }
  }
  return 0;
}