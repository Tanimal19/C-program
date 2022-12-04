//CC: 2
#include <stdio.h>
 
int main() {
    int N;
    scanf("%d", &N);
 
    for (int i = 0; i < N; ++i) {
        unsigned long long a;
        scanf("%llu", &a);
        for (int j = 0; j < 60; j += 5) {
            unsigned long long b = (a >> j) & 0b11111;
            putchar((char)((int)'a' + b));
        }
    }
    putchar('\n');
 
    return 0;
}
