#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2147483647

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 }, D{ 0 };
    cin >> N >> D;

    vector<int> map(D + 1, MAX);
    vector<pair<int, int>> vec[10001];

    int iStart{ 0 }, iEnd{ 0 }, iDis{ 0 };
    for (int i = 0; i < N; i++)
    {
        cin >> iStart >> iEnd >> iDis;
        vec[iEnd].push_back({ iStart, iDis });
    }

    map[0] = 0;
    for (int  i = 1; i <= D; i++)
    {
        if (vec[i].size() == 0)
        {
            map[i] = map[i - 1] + 1;
        }
        else
        {
            for (auto v:vec[i])
            {
                map[i] = min(map[i], min(map[i - 1] + 1, map[v.first] + v.second));
            }
        }
    }

    cout << map[D] << '\n';

    return 0;
}