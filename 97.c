#include <stdio.h>

int main(){
	int park, bike;
	int i, j;
	
	scanf("%d", &park);
	int park_x[park], park_y[park], park_cap[park];
	for(i=0;i<park;i++){
		scanf("%d%d%d", &park_x[i], &park_y[i], &park_cap[i]);
	}

	scanf("%d", &bike);
	int bike_x[bike], bike_y[bike];
	for(i=0;i<bike;i++){
		scanf("%d%d", &bike_x[i], &bike_y[i]);
	}
	

	//計算腳踏車和停車場距離
	int dis[park], cap[park]; 
	for(i=0;i<park;i++){
		cap[i] = 0;
	}

	for(i=0;i<bike;i++){
		int x[park], y[park], fpark;
		int k=0;
		while(k<park){
			if(park_cap[k]>0){
				fpark = k;
				k=park; 
			}
			else{
				k++;
			}
		}

		for(j=0;j<park;j++){
			x[j] = bike_x[i] - park_x[j];
			x[j] = x[j]<0 ? -x[j] : x[j];
			y[j] = bike_y[i] - park_y[j];
			y[j] = y[j]<0 ? -y[j] : y[j];
			dis[j] = x[j]+y[j];		//計算距離
			
			if(park_cap[j]>0){		//判斷是否滿位			
				if(dis[j]<dis[fpark]){		// 比較距離遠近
					fpark = j;
				}
				else if(dis[j]==dis[fpark]){
					if(park_x[j]<park_x[fpark]){
						fpark = j;
					}
					else if(park_x[j]==park_x[fpark]){
						if(park_y[j]<park_y[fpark]){
							fpark = j;
						}
					}
				}
			}
			#ifdef DEBUG
			printf("%d\n", fpark);
			#endif	
		}
		park_cap[fpark]--;
		cap[fpark]++;
		
	}
	for(i=0;i<park;i++){
		printf("%d\n", cap[i]);
	}
	return 0;
}