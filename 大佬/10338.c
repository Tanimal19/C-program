// CC: 21
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if the token starting from p is s
int nextIs(char buf[2002], int p, int rb, const char s[]) {
	int n = (int) strlen(s), ans = (p + n - 1 <= rb);
	for (int i = 0; i < n && ans; ++i)
		ans &= (buf[p + i] == s[i]);
	return ans && (buf[p + n] == '\0' || buf[p + n] == ' ');
}
// find the other end of the token
int findEnd(char buf[2002], const char token[6][10], int lb, int rb) {
	if (lb > rb) return -1;
	if (buf[lb] == '!') return findEnd(buf, token, lb+2, rb);
	int p = -1;
	if (buf[lb] == '(') {
		int sum = 1;
		for (int i = lb + 1; i <= rb; ++i) {
			sum += (buf[i] == '(');
			sum -= (buf[i] == ')');
			if (sum == 0) {
				p = i;
				break;
			}
		}
		return p;
	}
	for (int i = lb; i <= rb; ++i) {
		if (buf[i+1] == ' ' || buf[i+1] == '\0') {
			p = i;
			break;
		}
	}
	return p;
}

int parse(char buf[2002], const char token[6][10], int lb, int rb) {
	// printf("\033[1;32mDebug [%d, %d]\033[0m\n", lb, rb);
	if (lb > rb) return 2;
	if (buf[lb] == '(') {
		if (buf[rb] != ')') return 2;

		int p1 = findEnd(buf, token, lb+2, rb-2);
		if (p1 == -1) return 2;

		int op = (nextIs(buf, p1+2, rb-2, token[3]) + nextIs(buf, p1+2, rb-2, token[4]) * 2);
		if (op == 0) return 2;

		int p2 = findEnd(buf, token, p1 + 5, rb-2);
		if (p2 == -1 || p2 != rb - 2) return 2;

		int ans1 = parse(buf, token, lb+2, p1);
		int ans2 = parse(buf, token, p1+5, p2);
		if (ans1 == 2 || ans2 == 2) return 2;
		if (op == 1) return ans1 && ans2;
		return ans1 || ans2;
	}
	if (nextIs(buf, lb, rb, token[5])) {
		int ans = parse(buf, token, lb+2, rb);
		return (ans == 2 ? 2 : 1 - ans);
	}
	// Remember to check cases like "true false"
	if (nextIs(buf, lb, rb, token[0])) return 2 * (lb + 4 != rb);
	if (nextIs(buf, lb, rb, token[1])) return 2 - (lb + 3 == rb);
	return 2;
}

int main() {
	char buf[2002];
	const char token[6][10] = {
		"false",
		"true",
		"invalid",
		"&&",
		"||",
		"!",
	};

	// read at most 2001 chars
	// and stops on \n
	while (scanf("%2001[^\n]", buf) != EOF) {
		getchar();
		int len = (int) strlen(buf);
		int ans = parse(buf, token, 0, len-1);
		puts(token[ans]);
	}
}
