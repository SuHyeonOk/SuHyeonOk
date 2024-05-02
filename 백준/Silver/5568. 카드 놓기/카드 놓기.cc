#include <iostream>
#include <set>
using namespace std;

int n = 0, k = 0;
string arr[10];
bool visited[10];
set<string> s;

void BT(int _depth, string _temp)
{
    if (k == _depth)
    {
        s.insert(_temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (false == visited[i])
        {
            visited[i] = true;
            BT(_depth + 1, _temp + arr[i]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BT(0, "");

    cout << s.size();

    return 0;
}