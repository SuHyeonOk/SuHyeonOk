#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ﻿iFinal{ 0 }, S{ 0 }, G{ 0 }, U{ 0 }, D{ 0 };
vector<bool> visited;

void BFS(int _node)
{
	queue < pair<int, int>> q;
	q.push({ _node, 0 });
	visited[_node] = true;

	bool bFind{ false };
	while (false == q.empty())
	{
		int iNext{ q.front().first };
		int iCount{ q.front().second };
		q.pop();

		
		if (iNext == G)
		{
			bFind = true;
			cout << iCount << '\n';
			return;
		}

		if (iNext + U <= ﻿iFinal && visited[iNext + U] == false)
		{
			visited[iNext + U] = true;
			q.push({ iNext + U, iCount + 1 });
		}

		if (iNext - D >= 1 && visited[iNext - D] == false)
		{
			visited[iNext - D] = true;
			q.push({ iNext - D, iCount + 1 });
		}
	}

	if (false == bFind)
	{
		cout << "use the stairs\n";
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> ﻿iFinal >> S >> G >> U >> D;
	visited.resize(﻿iFinal + 1);

	if (S < G && U == 0 || S > G && D == 0)
	{
		cout << "use the stairs\n";
		return 0;
	}

	BFS(S);

	return 0;
}