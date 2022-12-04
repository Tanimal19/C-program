// CC: 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint64_t dfs(int N, int K, const uint64_t a[], int i, uint64_t sum[], uint64_t sum2[], uint64_t tot) {
	if (i == N) return tot;
	uint64_t ans = 0xFFFFFFFFFFFFFFFF;

	for (int j = 0; j < K && !(j > 0 && sum[j-1] == 0); ++j) {
		tot -= sum2[j];
		sum[j] += a[i];
		sum2[j] = sum[j] * sum[j];
		tot += sum2[j];

		uint64_t cur = dfs(N, K, a, i+1, sum, sum2, tot);
		if (cur < ans) ans = cur;

		tot -= sum2[j];
		sum[j] -= a[i];
		sum2[j] = sum[j] * sum[j];
		tot += sum2[j];
	}

	return ans;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	uint64_t a[N];
	for (int i = 0; i < N; ++i)
		scanf("%lu", a + i);

	uint64_t sum[N], sum2[K];
	memset(sum, 0, sizeof(sum));
	memset(sum2, 0, sizeof(sum2));

	printf("%lu", dfs(N, K, a, 0, sum, sum2, 0ul));
}