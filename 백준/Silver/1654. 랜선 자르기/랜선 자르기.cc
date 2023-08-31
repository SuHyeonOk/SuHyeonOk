#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K{ 0 }, N{ 0 };
	cin >> K >> N;

	unsigned int iMax{ 0 };
	vector<unsigned int>vec(K);

	for (int i = 0; i < K; i++)
	{
		cin >> vec[i];
		iMax = max(iMax, vec[i]);
	}

	unsigned int iLeft{ 1 }, iRight{ iMax }, iPivot{ 0 }, iReault{ 0 };

	while (iLeft <= iRight)
	{
		iPivot = (iLeft + iRight) / 2;
		unsigned int iTarget{ 0 };

		for (int i = 0; i < K; i++)
		{
			iTarget += vec[i] / iPivot;
		}

		if (iTarget >= N)
		{
			iLeft = iPivot + 1;
			iReault = max(iRight, iPivot);
		}
		else
		{
			iRight = iPivot - 1;
		}
	}

	cout << iRight << '\n';

	return 0;
}