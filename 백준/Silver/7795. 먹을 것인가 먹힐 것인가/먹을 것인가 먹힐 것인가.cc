#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
vector<int> a, b;

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a = vector<int>(n);
		b = vector<int>(m);

		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)scanf("%d", &b[i]);
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int left = 0, right = m;
			while (left + 1 < right) {
				int mid = (left + right) / 2;
				if (a[i] > b[mid])left = mid;
				else right = mid;
			}
			ans += left;
			if (a[i] > b[left])ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}