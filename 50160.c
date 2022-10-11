#include <stdio.h>

#define a 3
#define b 2
#define c 1
#define n 0

int main(){
	int round;
	int health, reco;
	int base[4], extra[4], cool[4];
	int cd[4] = {0}, first[4] = {0};
	extra[n] = 0, cool[n] = 0;

	scanf("%d", &round);
	scanf("%d%d", &health, &reco);
	int i;
	for(i=3;i>0;i--){
		scanf("%d%d%d", &base[i], &extra[i], &cool[i]);
	}
	scanf("%d", &base[n]);

	int damage[4];
	int roundp[4] = {0};
	int f;
	int maxhp = health;

	int j;
	
	for(i=0;i<round;i++){
		int max = 0;
		for(j=0;j<4;j++){
			if(cd[j] == 0){	//already cool down?
				if(first[j] == 0){	//first time?
					if(i <= cool[j]){
						damage[j] = base[j];
					}
					else{
						damage[j] = base[j] + extra[j] * (i-cool[j]);
					}
				}
				else{
					if(i-roundp[j] >= cool[j]){
						f = i-roundp[j]-cool[j];
						if(f < 0) f = 0;
						damage[j] = base[j] + extra[j] * f;
					}
				}
				
				if(damage[j] >= damage[max]){
					max = j;
				}
			}
		}

		cd[max] = cool[max];	//cd reset
		for(j=0;j<4;j++){
			if(cd[j] > 0) cd[j]--;
		}
		first[max] = 1;
		roundp[max] = i;

		health -= damage[max];
		if(health <= 0){
			printf("%d", health);
			return 0;
		}
		else{
			printf("%d ", health);
			health += reco;
			if(health >= maxhp) health = maxhp;
		}
		
		#ifdef DEBUG
		printf("a:%d b:%d c:%d n:%d\n", cd[a], cd[b], cd[c], cd[n]);
		#endif
	}


	return 0;
}