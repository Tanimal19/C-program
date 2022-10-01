#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int bn=n+2;
	int arr[bn][bn];

	int i, j;
	for(i=0;i<bn;i++){
		for(j=0;j<bn;j++){
			if(i==0 || i==bn-1 || j==0 || j==bn-1){
				arr[i][j]=0;
			}
			else{
				scanf("%d", &arr[i][j]);
			}
		}
	}

	#ifdef DEBUG
	for(i=0;i<bn;i++){
		for(j=0;j<bn;j++){
			printf("%d ", arr[i][j]);
		}
		printf("%d\n");
	}
	#endif

	int intersection=0, tjunction=0, turn=0, deadend=0;
	for(i=0;i<bn;i++){
		for(j=0;j<bn;j++){
			if(arr[i][j]==1){
				switch((arr[i-1][j]==1)+(arr[i+1][j]==1)+
						(arr[i][j-1]==1)+(arr[i][j+1]==1)){
					case 4:
						intersection++;
						break;
					case 3:
						tjunction++;
						break;
					case 2:
						if((arr[i-1][j]==1 && arr[i+1][j]==1)
							||(arr[i][j-1]==1 && arr[i][j+1]==1)){
							break;
						}else{
							turn++;
							break;
						}
					case 1:
						deadend++;
				}
			}		
		}
	}
	printf("%d\n", intersection);
	printf("%d\n", tjunction);
	printf("%d\n", turn);
	printf("%d", deadend);

	return 0;
}