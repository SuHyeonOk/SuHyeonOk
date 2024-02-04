#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    string input = "";
    unordered_map<string, int> um;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        um[input]++;
    }

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        if (0 != um[input])
        {
            ++result;
        }
    }

    cout << result;

    return 0;
}