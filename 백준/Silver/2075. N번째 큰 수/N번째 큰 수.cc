#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Max = N * N;
    vector<int> vec(Max);

    for (int i = 0; i < Max; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), greater<int>());

    cout << vec[N - 1];

    return 0;
}