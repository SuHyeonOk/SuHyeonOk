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

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    int Result = 1, Temp = vec[0];
    for (int i = 1; i < N; ++i)
    {
        if (vec[i] - Temp + 1 > L)
        {
            ++Result;
            Temp = vec[i];
        }
    }

    cout << Result;

    return 0;
}