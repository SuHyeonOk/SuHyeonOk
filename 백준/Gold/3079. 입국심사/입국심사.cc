#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n{ 0 }, m{ 0 };
    cin >> n >> m;

    vector<int> vec(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

	long long start = 1, end = vec.back() * m;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;

		for (long long i = 0; i < n; i++) {
			cnt += mid / vec[i];
			if (cnt > m)
				break;
		}

		if (cnt >= m) { // 충분하므로 시간을 줄여야한다.
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start;

    return 0;
}