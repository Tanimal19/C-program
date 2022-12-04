//CC: 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// You can use __builtin_popcountll to do this,
// but I'm writing this for fun.
// If you want to know what this does,
// feel free to ask me by any means.
int popcount(uint64_t a) {
	a = (a & 0x5555555555555555) + ((a & 0xAAAAAAAAAAAAAAAA) >> 1);
	a = (a & 0x3333333333333333) + ((a & 0xCCCCCCCCCCCCCCCC) >> 2);
	a = (a & 0x0F0F0F0F0F0F0F0F) + ((a & 0xF0F0F0F0F0F0F0F0) >> 4);
	a = (a & 0x00FF00FF00FF00FF) + ((a & 0xFF00FF00FF00FF00) >> 8);
	a = (a & 0x0000FFFF0000FFFF) + ((a & 0xFFFF0000FFFF0000) >> 16);
	a = (a & 0x00000000FFFFFFFF) + ((a & 0xFFFFFFFF00000000) >> 32);
	return (int) a;
}

void solve(int n, int g[64][64], uint64_t* ans, uint64_t choosed, int cnt, int i) {
	if (i == n || popcount(*ans) <= cnt) {
		if (popcount(*ans) > cnt)
			*ans = choosed;
		return;
	}

	int need = 0;
	for (int j = 0; j < i; ++j)
		need |= g[i][j] && ((choosed >> j & 1) == 0);
	
	// This order guarantees a solution of lexicographical minimum
	solve(n, g, ans, choosed | (1ull << i), cnt+1, i+1);
	if (need == 0)
		solve(n, g, ans, choosed, cnt, i+1);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int g[64][64];
	memset(g, 0, sizeof(g));
	for (int u, v, i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}

	uint64_t ans = (uint64_t) -1ll, choosed = 0;
	int cnt = 0;
	solve(n, g, &ans, choosed, cnt, 0);

	for (int i = 0; i < n; ++i) {
		if (ans >> i & 1)
			printf("%d\n", i);
	}
}
