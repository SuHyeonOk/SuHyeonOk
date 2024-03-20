#include <iostream>
using namespace std;

int k = 0;
int s[13]{ 0, };
int print[6]{ 0, };
bool visited[13]{ false, };

void DFS(int _depth, int _i)
{
    if (6 == _depth)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << print[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = _i; i < k; i++)
    {
        if (true == visited[i])
        {
            continue;
        }

        visited[i] = true;
        print[_depth] = s[i];
        DFS(_depth + 1, i + 1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true)
    {
        cin >> k;

        if (k == 0)
        {
            break;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> s[i];
        }

        DFS(0, 0);
        cout << '\n';
    }

    return 0;
}