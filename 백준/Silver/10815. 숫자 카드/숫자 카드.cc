#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int N{ 0 }, M{ 0 };

	cin >> N;
	vector<int> ns(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ns[i];
	}

	cin >> M;
	vector<int> ms(M);
	for (int i = 0; i < M; i++)
	{
		cin >> ms[i];
	}

	sort(ns.begin(), ns.end()); // 정렬

	bool bFind{ false };
	int iLeft{ 0 }, iRight{ static_cast<int>(ns.size() - 1) }, iPivot{ 0 };

	for(int i = 0; i < M; ++i)
	{
		bFind = false;
		iLeft = 0;
		iRight = static_cast<int>(ns.size() - 1);

		while (iLeft <= iRight)
		{
			iPivot = (iLeft + iRight) / 2;

			if (ns[iPivot] == ms[i])
			{
				bFind = true;
				cout << "1 ";
				break;
			}
			else if (ns[iPivot] < ms[i])
			{
				iLeft = iPivot + 1;
			}
			else
			{
				iRight = iPivot - 1;
			}
		}
		
		if (false == bFind)
		{
			cout << "0 ";
		}
	
	}

	return 0;
}