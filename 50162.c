#include <stdio.h>

int main(){
	int DPS[5000], d=0;
	int Heal[5000], h=0;
	int Tank[5000], t=0;
	int disok = 2, hisok = 0, tisok = 0;
	
	int queue[3000][5];
	int team = 0;
	
	int p;
	int i;
	for(i=0;i<5000;i++){
		DPS[i] = -1;
		Heal[i] = -1;
		Tank[i] = -1;
	}

	while(scanf("%d", &p) != EOF){
		if(p%3==0){
			DPS[d] = p;
			d++;
			if(d==5000) d=0;	//reset
		}
		else if(p%3==1){
			Heal[h] = p;
			h++;
			if(h==5000) h=0;	//reset
		}
		else{
			Tank[t] = p;
			t++;
			if(t==5000) t=0;	//reset
		}

		//check if party formed
		if(DPS[disok] != -1 && Heal[hisok] != -1 && Tank[tisok] != -1){
			int d1 = disok-2;
			int d2 = disok-1;

			if(d1 < 0) d1 = 5000 + d1;
			if(d2 < 0) d2 = 5000 + d2;

			queue[team][0] = DPS[disok-2];
			queue[team][1] = DPS[disok-1];
			queue[team][2] = DPS[disok];
			queue[team][3] = Heal[hisok];
			queue[team][4] = Tank[tisok];

			DPS[disok-2] = -1;
			DPS[disok-1] = -1;
			DPS[disok] = -1;
			Heal[hisok] = -1;
			Tank[tisok] = -1;

			disok += 3;		//next team
			hisok ++;
			tisok ++;
			if(disok >= 5000){
				disok = 5000 - disok + 2;
			}

			team ++;
		}
	}

	int j;
	for(i=0;i<team;i++){
		for(j=0;j<5;j++){
			printf("%d%c", queue[i][j], j==4 ? '\n':' ');
		}
	}

	return 0;
}