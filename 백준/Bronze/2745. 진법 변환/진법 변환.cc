#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
/*
2745_진법 변환
1112kb	0ms
*/
#include <cstdio>

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	char n[31];
	int b;
	scanf("%s %d", n, &b);

	int i = 0, res = 0;
	while (n[i]) {
		res = res * b + (n[i] < 'A' ? n[i] - '0' : n[i] - 'A' + 10);
		++i;
	}

	printf("%d\n", res);
	return 0;
}