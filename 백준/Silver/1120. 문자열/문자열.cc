#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int Count = 0;
    int Ans = 0x3f3f3f3f;
    for (int i = 0; i <= b.size() - a.size(); i++) 
    {
        Count = 0;
        for (int j = 0; j < a.size(); j++) 
        {
            if (a[j] != b[j + i]) Count++;
        }
        Ans = min(Ans, Count);
    }
    cout << Ans << '\n';

	return 0;
}