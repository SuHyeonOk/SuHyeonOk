#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    size_t N = 0;
    cin >> N;

    set<int> s;
    int input = 0;

    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        s.insert(input);
    }

    size_t M = 0;
    cin >> M;

    for (size_t i = 0; i < M; i++)
    {
        cin >> input;
        if (s.end() == s.find(input)) // 없는 경우
        {
            cout << 0 << ' ';
        }
        else // 있는 경우
        {
            cout << 1 << ' ';
        }
    }

    return 0;
}