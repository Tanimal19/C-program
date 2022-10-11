#include "intersection.h"

void intersection(int map[100][100], int result[4]){
	int i, j;
	int map2[102][102];

	for(i=0;i<102;i++){
		for(j=0;j<102;j++){
			if(i==0 || i==101 || j==0 || j==101){
				map2[i][j]=0;
			}
			else{
				map2[i][j] = map[i-1][j-1];
			}
		}
	}

	result[0]=0, result[1]=0, result[2]=0, result[3]=0;
	for(i=0;i<102;i++){
		for(j=0;j<102;j++){
			if(map2[i][j]==1){
				switch((map2[i-1][j]==1)+(map2[i+1][j]==1)+
						(map2[i][j-1]==1)+(map2[i][j+1]==1)){
					case 4:
						result[0]++;
						break;
					case 3:
						result[1]++;
						break;
					case 2:
						if((map2[i-1][j]==1 && map2[i+1][j]==1)
							||(map2[i][j-1]==1 && map2[i][j+1]==1)){
							break;
						}else{
							result[2]++;
							break;
						}
					case 1:
						result[3]++;
				}
			}		
		}
	}

}