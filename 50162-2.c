#include <stdio.h>
#define dps 0
#define heal 1
#define tank 2

int main(){
	int wait;

	int queue[3000][5];
	int team[3];
	team[dps] = 0;
	team[heal] = 0;
	team[tank] = 0;

	int d = 0;

	while(scanf("%d", &wait) != EOF){
		switch(wait % 3){
			case 0:
				if(team[dps] < 3000){
					queue[team[dps]][d] = wait;
					d++;
					if(d == 3){
						d = 0;	//reset
						team[dps] ++; 	//next team
					}
				}
				break;

			case 1:
				if(team[heal] < 3000){
					queue[team[heal]][3] = wait;
					team[heal] ++;
				}
				break;

			case 2:
				if(team[tank] < 3000){
					queue[team[tank]][4] = wait;
					team[tank] ++;
				}
				break;
		}
	}

	int min = 3000;
	int i, j;
	for(i=0 ; i<3 ; i++){
		if(team[i] <= min){
			min = team[i];
		}
	}

	for(i=0 ; i<min ; i++){
		for(j=0 ; j<5 ; j++){
			printf("%d%c", queue[i][j], j==4 ? '\n':' ');
		}
	}

	return 0;
}