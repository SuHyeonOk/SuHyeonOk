#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int A = 0, B = 0, N = 0;
	cin >> A >> B >> N;

	int Result = 0;
	while (N--) 
	{
		A %= B;
		A *= 10;
		Result = A / B;
	}
	cout << Result;

    return 0;
}