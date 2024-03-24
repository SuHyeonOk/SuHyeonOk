#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int h = 0;
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        cin >> h;
        s.push(h);
    }

    int Result = 1;
    size_t Size = s.size();
    for (size_t i = 0; i < Size; i++)
    {
        if (h < s.top())
        {
            h = s.top();
            ++Result;
        }
        s.pop();
    }

    cout << Result;

    return 0;
}