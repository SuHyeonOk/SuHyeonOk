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

    int Count = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < N; ++i)
    {
        if (vec[i] == vec[i - 1])
        {
            ++Count;
            continue;
        }

        int Distance = vec[i] - vec[i - 1];
        pq.push(Distance);
    }

    int Ans = 0;
    for (int i = 0; i < (N - Count) - (K - 1); ++i)
    {
        Ans += pq.top();
        pq.pop();
    }

    cout << Ans;

    return 0;
}