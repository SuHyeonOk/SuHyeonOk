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

    vector<int> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<int>());

    int Result = -1;
    for (int i = 0; i < N - 2; ++i)
    {
        int a = vec[i];
        int b = vec[i + 1];
        int c = vec[i + 2];
        if (a + b > c && a + c > b && b + c > a)
        {
            Result = a + b + c;
            break;
        }
    }

    cout << Result;

    return 0;
}