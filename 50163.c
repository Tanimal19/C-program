#include <stdio.h>

int main(){
	int c;
	scanf("%d", &c);
	int seat[c*100];
	int pos = 0;
	int empty[c*100];
	empty[0] = -1;
	int in=0, out=0;
	int request;

	while(scanf("%d", &request) != EOF){
		printf("%d\n", pos);

		if(request==1){
			if(empty[out] != -1){
				seat[empty[out]] = 1;
				out++;
			} 
			else{
				seat[pos] = 1;
				pos++;
			}
		}
		else{
			if((pos+1)%5 == 0 || (pos+1)%5 == 3){
				empty[in] = pos;
				pos ++;
				in ++;
			}
			seat[pos] = 2;
			seat[pos+1] = 2;
			pos += 2;
		}
	}

	int i;
	for(i=0;i<pos;i++){
		if(seat[i] == 1){
			int s = (i+1)%5;
			int c = ((i+1)-s)/5 + 1;
			int r = ((i+1)-c*5)/100 + 1;
			printf("%d %d %d\n", c, r, s);
		}
		else if(seat[i] == 2){
			int s = (i+1)%5;
			int c = ((i+1)-s)/5 + 1;
			int r = ((i+1)-c*5)/100 + 1;
			printf("%d %d %d %d %d %d\n", c, r, s, c, r, s+1);
			i++;
		}
	}

	return 0;
}

