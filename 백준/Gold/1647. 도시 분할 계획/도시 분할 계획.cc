#include <iostream>
#include <vector>
#include <algorithm>
#include<tuple>

using namespace std;

int N{ 0 }, M{ 0 }, ret{ 0 };
vector<int> parent;
vector<tuple<int, int, int>> vec;

int find(int num) {
	if (!parent[num]) return num;
	else return parent[num] = find(parent[num]);
}

void Union(int a, int b) { parent[a] = b; }

void Kruskal()
{
	int edge = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (edge == N - 2)
		{
			return;
		}

		int n1 = find(get<1>(vec[i]));
		int n2 = find(get<2>(vec[i]));

		if (n1 != n2) 
		{
			edge++;
			ret += get<0>(vec[i]);
			Union(n1, n2);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vec.resize(M + 1);
	parent.resize(N + 1);

	int A{ 0 }, B{ 0 }, C{ 0 };
	for (int i = 0; i < M; i++) 
	{
		cin >> A >> B >> C;
		vec[i] = make_tuple(C, A, B);
	}
	sort(vec.begin(), vec.end());

	Kruskal();

	cout << ret;
}