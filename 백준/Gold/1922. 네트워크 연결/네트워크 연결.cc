#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

vector<int> parent;

int find_parent(int x)
{
	if (parent[x] == x) // 자기자신이 부모일 경우 
	{
		return x;
	}
	else // 부모 노드 찾기
	{
		return parent[x] = find_parent(parent[x]);
	}
}

bool union_node(int _start, int _end)
{
	_start = find_parent(_start);
	_end = find_parent(_end);

	if (_start == _end) // 부모가 같다면 결합 시 사이클 이므로
	{
		return false; // 연결하지 않는다.
	}
	else
	{
		parent[_start] = _end; // 결합 & 부모로 기록
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N{ 0 }, M{ 0 }, A{ 0 }, B{ 0 }, C{ 0 };
	cin >> N >> M;

	parent.resize(N + 1);
	vector<tuple<int, int, int>> vec(M);

	// 부모를 자기 자신으로 초기화
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// 그래프 정보 저장
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		vec[i] = make_tuple(C, A, B);
	}

	// 가중치가 작은 간선부터 오름차순으로 정렬 (그래서 C가 가장 앞)
	sort(vec.begin(), vec.end());

	// 간선들 결합 (MST 찾기)
	long long ans{ 0 }; // -21~21억 사이의 값을 더해야 해서 long long
	for (int i = 0; i < M; i++)
	{
		/*
		get<0>(vec[i]) : 가중치
		get<1>(vec[i]) : 출발 노드
		get<2>(vec[i]) : 도착 노드
		*/
		if (true == union_node(get<1>(vec[i]), get<2>(vec[i]))) // false : 사이클 발생
		{
			ans += get<0>(vec[i]); // 가중치 더하기
		}
	}

	cout << ans << '\n';
}