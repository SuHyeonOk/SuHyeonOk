#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int M = 0;
    string Name = "", Type = "";
    unordered_map<string, int> um;
    while (N--)
    {
        cin >> M;
        um.clear();

        while (M--)
        {
            cin >> Name >> Type;
            ++um[Type];
        }

        int ans = 1;
        for (unordered_map<string, int>::iterator it = um.begin(); it != um.end(); it++)
        {
            ans *= (it->second + 1);
        }
        ans -= 1; // 둘 다 안입은 경우 제외
        cout << ans << '\n';
    }

    return 0;
}