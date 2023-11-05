//백준 2776 암기왕
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		vector<int> s;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			s.push_back(num);
		}
		sort(s.begin(), s.end());
		cin >> M;
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (binary_search(s.begin(), s.end(), num))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}