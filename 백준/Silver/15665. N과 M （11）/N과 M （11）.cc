#include<iostream>
#include<algorithm>
using namespace std;

bool check[9];
int seq[9], ans[9];
int N, M;

void dfs(int x, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	int tmp = -1;

	for (int i = 0; i < N; i++)
	{
		if (tmp != seq[i]) // tmp는 직전에 골랐던 수
		{
			check[i] = true;
			ans[cnt] = seq[i];
			tmp = seq[i];
			dfs(i, cnt + 1);
			check[i] = false;
		}
	}
		
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> seq[i];
	
	sort(seq, seq + N); // 오름차순 정렬

	dfs(0, 0);
}