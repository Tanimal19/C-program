//CC: 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5

int dfs(int n, int id[MAXN*MAXN], int used[MAXN*MAXN], int tile[MAXN*MAXN][4], int i) {
	if (i == n * n) return 1;
	for (int j = 0; j < n * n; ++j) {
		int ok = 1;
		ok &= !used[j];
		ok &= !(i >= n && tile[j][1] != tile[id[i-n]][3]);
		ok &= !(i % n && tile[j][0] != tile[id[i-1]][2]);
		if (ok) {
			id[i] = j;
			used[j] = 1;
			if (dfs(n, id, used, tile, i + 1))
				return 1;
			used[j] = 0;
		}
	}
	return 0;
}

int main() {
	int n;
	int id[MAXN*MAXN], used[MAXN*MAXN];
	int tile[MAXN*MAXN][4];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n * n; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%d", &tile[i][j]);
		memset(used, 0, sizeof(used));

		int has = dfs(n, id, used, tile, 0);
		if (!has) puts("no solution");
		else {
			for (int i = 0; i < n * n; ++i) {
				printf("%d", id[i]);
				putchar(" \n"[i % n == n-1]);
			}
		}
	}
}
