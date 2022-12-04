//CC: 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 88

int dfs(int a[MAXN][MAXN][MAXN], int i, int j, int k, int v) {
	static const int dx[6] = {1, -1, 0, 0, 0, 0};
	static const int dy[6] = {0, 0, 1, -1, 0, 0};
	static const int dz[6] = {0, 0, 0, 0, 1, -1};

	a[i][j][k] = -1;
	int ans = 1;
	for (int d = 0; d < 6; ++d) {
		int ni = i + dx[d];
		int nj = j + dy[d];
		int nk = k + dz[d];
		if (a[ni][nj][nk] == v)
			ans += dfs(a, ni, nj, nk, v);
	}

	return ans;
}

int main() {
	int N;
	scanf("%d", &N);

	int a[MAXN][MAXN][MAXN];
	memset(a, -1, sizeof(a));
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			for (int k = 1; k <= i; ++k)
				scanf("%d", &a[i][j][k]);

	int mxv = 0, mxc = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			for (int k = 1; k <= i; ++k)
				if (a[i][j][k] != -1) {
					int v = a[i][j][k];
					int c = dfs(a, i, j, k, v);
					if (c > mxc || (c == mxc && v > mxv)) {
						mxc = c;
						mxv = v;
					}
				}

	printf("%d %d\n", mxv, mxc);
}
