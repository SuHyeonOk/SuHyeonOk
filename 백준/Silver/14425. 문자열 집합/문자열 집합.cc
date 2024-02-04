#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    string input = "";
    unordered_set<string> us;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        us.insert(input);
    }

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        if (us.end() != us.find(input))
        {
            ++result;
        }
    }

    cout << result;

    return 0;
}