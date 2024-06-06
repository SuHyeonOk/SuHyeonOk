#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, L = 0;
    cin >> N >> L;

    vector<pair<int, int>> vec(N);
    int Start = 0, End = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Start >> End;
        vec[i] = { Start, End };
    }

    sort(vec.begin(), vec.end());

    int Next = 0, Count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (Next < vec[i].first)
        {
            Next = vec[i].first;
        }

        while (Next < vec[i].second)
        {
            Next += L;
            Count++;
        }
    }

    cout << Count;

    return 0;
}
