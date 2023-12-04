#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	int cnt = 0;
	while (scanf("%d", &n) != EOF) {
		if (n > 0) cnt++;
	}

	cout << cnt;

}