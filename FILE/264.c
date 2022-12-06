#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define MAXN 65535
 
int main(){
    char filename[200];
    scanf("%s", filename);
 
    FILE *fin = fopen(filename, "rb");
    assert(fin != NULL);

    int tbuf[2];
    int size;
    fread(tbuf, 4, 1, fin);
    size = tbuf[0];

    int16_t buf[size];
    int appear[MAXN] = {0};

    while(fread(buf, 2, size, fin) != 0){
        for(int i=0 ; i<size ; i++){
            appear[buf[i] + 32768] ++;
        }
    }
    
    fclose(fin);
 
    int max = 0, maxi = -1;
    for(int i=0 ; i<MAXN ; i++){
        if(appear[i] >= max){
            max = appear[i];
            maxi = i;
            if(max > size/2) break;
        }
    }
 
    printf("%d\n%d", maxi - 32768, max);
 
    return 0;
}