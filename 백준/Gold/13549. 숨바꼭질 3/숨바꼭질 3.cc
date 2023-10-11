#include <iostream>
#include <deque>
using namespace std;

#define MAX 100000+1
int nodeStart{ 0 }, nodeEnd{ 0 };
int visited[MAX]{ false };

int BFS()
{
    deque<int> dq;
	dq.push_back(nodeStart);
	visited[nodeStart] = 1;

    while (false == dq.empty())
    {
		int node = dq.front();
		dq.pop_front();

        if (node == nodeEnd)
        {
			return visited[nodeEnd] - 1;
        }

		if (node * 2 < MAX && false == visited[node * 2])
		{
			dq.push_front(node * 2);
			visited[node * 2] = visited[node];
		}

		if (node - 1 >= 0 && false == visited[node - 1])
		{
			dq.push_back(node - 1);
			visited[node - 1] = visited[node] + 1;
		}

		if (node + 1 < MAX && false == visited[node + 1])
		{
			dq.push_back(node + 1);
			visited[node + 1] = visited[node] + 1;
		}

	}

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> nodeStart >> nodeEnd;

    cout << BFS();

    return 0;
}