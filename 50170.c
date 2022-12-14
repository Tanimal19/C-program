#include <stdio.h>
#include <string.h>

void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
	int h = (bottom_right - upper_left) / n_col +1;
	int w = (bottom_right - upper_left) % n_col +1;
	for(int i=0 ; i<h ; i++)
		for(int j=0 ; j<w ; j++)
			*(upper_left + i*n_col + j) = fill;
}

void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
	int h = (bottom_left - upper_right) / n_col +2;
	int w = n_col - ((bottom_left - upper_right) % n_col) +1;
	for(int i=0 ; i<h ; i++)
		for(int j=0 ; j<w ; j++)
			*(upper_right - w + 1 + i*n_col + j) = fill;
}

int main(){
        int row, col, type, row1, col1, row2, col2, fill;
        scanf("%d%d%d", &row, &col, &type);
        int arr[row][col];
        memset(&(arr[0][0]), 0, sizeof(int) * row * col);
        while(scanf("%d%d%d%d%d", &row1, &col1, &row2, &col2, &fill) != EOF){
                if(type == 0)
                        fill_rectangle_neg(&(arr[row1][col1]), &(arr[row2][col2]), row, col, fill);
                else
                        fill_rectangle_pos(&(arr[row1][col1]), &(arr[row2][col2]), row, col, fill);
        }
        for(int i = 0; i < row; i++)
                for(int j = 0; j < col; j++)
                        printf("%d%c", arr[i][j], j == col - 1 ? '\n' : ' ');
        return 0;
}