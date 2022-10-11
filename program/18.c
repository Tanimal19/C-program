#include <stdio.h>

int main(){
	int r, c;
	scanf("%d%d", &r, &c);

	int br=r+2, bc=c+2;
	int arr[br][bc];

	int i, j;
	for(i=0;i<br;i++){
		for(j=0;j<bc;j++){
			if(i==0 || i==br-1 || j==0 || j==bc-1){
				arr[i][j]=0;
			}
			else{
				scanf("%d", &arr[i][j]);
			}
		}
	}

	#ifdef DEBUG
	for(i=0;i<br;i++){
		for(j=0;j<bc;j++){
			printf("%d ", arr[i][j]);
		}
		printf("%d\n");
	}
	#endif

	for(i=0;i<br;i++){
		for(j=0;j<bc;j++){
			int a = arr[i][j];
			if(a>arr[i-1][j] && a>arr[i+1][j] && a>arr[i][j-1] && a>arr[i][j+1]){
				printf("%d\n", a);
			}
		}
	}

	return 0;
}