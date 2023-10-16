#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000
int nodeStart{ 0 }, nodeEnd{ 0 }, tempTime{ 0 }, result{ 1 };
int visited[MAX + 1]{ false };

void BFS()
{
	queue<pair<int,int>> q;
	q.push({ nodeStart, 0 });
	visited[nodeStart] = true;

	while (false == q.empty())
	{
		int node = q.front().first;
		int time = q.front().second;
		q.pop();
		visited[node] = true;

		if (node == nodeEnd) 
		{
			if (0 == tempTime)
			{
				tempTime = time;
			}
			else
			{
				if (tempTime == time)
				{
					++result;
				}
			}
		}

		if (node * 2 <= MAX && visited[node * 2] == false)
		{
			q.push({ node * 2, time + 1 });
		}
		if (node + 1 <= MAX && visited[node + 1] == false)
		{
			q.push({ node + 1, time + 1 });
		}
		if (node - 1 >= 0 && visited[node - 1] == false)
		{
			q.push({ node - 1, time + 1 });
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> nodeStart >> nodeEnd;

	BFS();
	
	cout << tempTime << '\n' << result;

	return 0;
}