#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0, M = 0;
    cin >> N >> M;

    int x = 0;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v[i] = x;
    }

    int Start = 0, End = 1, Count = 0;
    sort(v.begin(), v.end());

    while (Start <= End && End < N)
    {
        if (v[Start] + v[End] == M)
        {
            Count++;
        }

        if (End == N - 1)
        {
            Start++;
            End = Start + 1;
        }
        else
        {
            End++;
        }
    }

    cout << Count;

    return 0;
}