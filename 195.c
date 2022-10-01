#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int result = 0;

	int i=0, j, k;
	int x, y;
	int check;
	int board[3][3] = {{0}};
	int turn = 1;
	int flag = 0;

	if(n==0){
		flag=1;
	}
	while(flag==0){
		scanf("%d%d", &x, &y);
		if(0<=x && x<=2 && 0<=y && y<=2){ 	// legal
			if(board[x][y]==0){		// empty
				if(turn%2==1){		// black
					board[x][y]=1;
				}
				else{
					board[x][y]=-1;
				}
				turn++;
			}
		}
		// check row
	
		for(j=0;j<3;j++){
			check=0;
			for(k=0;k<3;k++){
				check+=board[j][k];
			}
			if(check==3){
				result=1;
				flag=1;
			}
			else if(check==-3){
				result=2;
				flag=1;
			}
		}
	

		// check column
		for(j=0;j<3;j++){
			check=0;
			for(k=0;k<3;k++){
				check+=board[k][j];
			}
			if(check==3){
				result=1;
				flag=1;
			}
			else if(check==-3){
				result=2;
				flag=1;
			}
		}

		if(((board[0][0]+board[1][1]+board[2][2])==3)||((board[0][2]+board[1][1]+board[2][0])==3)){
			result=1;
			flag=1;
		}
		else if(((board[0][0]+board[1][1]+board[2][2])==-3)||((board[0][2]+board[1][1]+board[2][0])==-3)){
			result=2;
			flag=1;
		}
		i++;
		if(i==n){
			flag=1;
		}
	}

	switch(result){
		case 0:
			printf("There is a draw.");
			break;
		case 1:
			printf("Black wins.");
			break;
		case 2:
			printf("White wins.");
			break;
	}

	return 0;
}