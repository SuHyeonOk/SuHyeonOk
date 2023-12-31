#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> vec(4001, vector<int>(4));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> vec[i][j];
		}
	}

	vector<int> A, B;
	for (int ac = 0; ac < N; ac++) 
	{
		for (int bd = 0; bd < N; bd++) 
		{
			A.push_back(vec[ac][0] + vec[bd][1]); // [0][0] + [0~n][1]
			B.push_back(vec[ac][2] + vec[bd][3]);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long result{ 0 };
	size_t size{ A.size() };
	for (size_t i = 0; i < size; i++)
	{
		int index = lower_bound(B.begin(), B.end(), -A[i]) - B.begin();
		int next_index = upper_bound(B.begin(), B.end(), -A[i]) - B.begin();

		result += (next_index - index);
	}

	cout << result << endl;

	return 0;

}