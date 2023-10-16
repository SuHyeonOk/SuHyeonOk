#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000
int nodeStart{ 0 }, nodeEnd{ 0 };
int save[MAX + 1]{ false }; // 경로에 값을 저장
int visited[MAX + 1]{ false }; // 방문 체크
vector<int> vec;

int BFS()
{
	visited[nodeStart] = true;

	queue<pair<int,int>> q;
	q.push({ nodeStart, 0 });

	while (false == q.empty())
	{
		int node = q.front().first;
		int time = q.front().second;
		q.pop();

		if (node == nodeEnd) 
		{
			int index = node;
			while (index != nodeStart)
			{
				vec.push_back(index);
				index = save[index];
			}
			vec.push_back(nodeStart);

			return time;
		}


		if (node * 2 <= MAX && visited[node * 2] == false)
		{
			q.push({ node * 2, time + 1 });
			visited[node * 2] = true;
			save[node * 2] = node;
		}
		if (node + 1 <= MAX && visited[node + 1] == false)
		{
			q.push({ node + 1, time + 1 });
			visited[node + 1] = true;
			save[node + 1] = node;
		}
		if (node - 1 >= 0 && visited[node - 1] == false)
		{
			q.push({ node - 1, time + 1 });
			visited[node - 1] = true;
			save[node - 1] = node;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> nodeStart >> nodeEnd;

	cout << BFS() << '\n';

	int size = vec.size() - 1;
	for (int i = size; i >= 0; i--)
	{
		cout << vec[i] << " ";
	}

	return 0;
}