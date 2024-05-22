#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    cin >> N >> K;

    vector<int> vec;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        vec.push_back(Temp);
    }
    sort(vec.begin(), vec.end());

    priority_queue<int> Qs;
    for (int i = 1; i < N; ++i)
    {
        if (vec[i] == vec[i - 1])
        {
            continue;
        }

        int Distance = vec[i] - vec[i - 1];
        Qs.push(Distance);
    }

    for (int i = 0; i < K - 1; ++i)
    {
        if (false == Qs.empty())
        {
            Qs.pop();
        }
    }

    int Ans = 0;
    while (false == Qs.empty())
    {
        Ans += Qs.top();
        Qs.pop();
    }

    cout << Ans;

    return 0;
}