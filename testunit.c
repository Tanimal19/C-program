#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    unsigned long long shelf = 2147483647;
    for(int i=0 ; i<1 ; i++){
        uint8_t book = 0;
        book = shelf >> 8*i;
        printf("%u\n", book);

        unsigned long long int test = pow(256, 7) * 128;
        printf("%lld\n", test);
        shelf &= test;

        printf("%lld\n", shelf);
    }
    return 0;
}