#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> V(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> V[i];
	}

	int B = 0, C = 0;
	cin >> B >> C;

	long long sum = 0;

	for (int i = 0; i < N; i++) 
	{
		if (V[i] <= B) 
		{
			sum++;
		}
		else 
		{
			sum += (V[i] - B) / C + 1;
			if ((V[i] - B) % C != 0)
			{
				sum++;
			}
		}
	}

	cout << sum;

	return 0;
}