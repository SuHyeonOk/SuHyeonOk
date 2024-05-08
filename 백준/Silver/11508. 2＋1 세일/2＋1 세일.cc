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
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end()); // 작~큰

    int End = N;
    int Sum = 0;

    while (End >= 3)
    {
        Sum += vec[End - 1];
        Sum += vec[End - 2];
        End -= 3;
    }

    if (3 > End)
    {
        for (int i = 0; i < End; i++)
        {
            Sum += vec[i];
        }
    }
    
    cout << Sum;

    return 0;
}