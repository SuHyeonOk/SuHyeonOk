#include <iostream>
#include <cmath>
using namespace std;

void Cantor(int _n) 
{
	// N = 0 인 경우 "-" 출력
	if (_n == 0) 
	{
		cout << "-";
		return;
	}

	// N번째 칸토어 집합 = N -1 번째 칸토어 집합을 2개 이은 것
	// 사이에 공백이 N - 1번째 칸토어 집합의 사이즈만큼 있어야 함
	Cantor(_n - 1);
	int Size = pow(3, _n - 1);
	for (int i = 0; i < Size; i++)
	{
		cout << ' ';
	}
	Cantor(_n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0;
	while (cin >> N) 
	{
		Cantor(N);
		cout << '\n';
	}

	return 0;
}