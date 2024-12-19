#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    string Name1 = "", Name2 = "";
    map<string, bool> m;
    while (N--)
    {
        cin >> Name1 >> Name2;

        if (Name1 == "ChongChong")
        {
            m[Name1] = true;
        }
        if (Name2 == "ChongChong")
        {
            m[Name2] = true;
        }

        if (true == m[Name1])
        {
            m[Name2] = true;
        }
        if (true == m[Name2])
        {
            m[Name1] = true;
        }
    }

    int Count = 0;
    for (auto& temp : m)
    {
        if (true == temp.second)
        {
            ++Count;
        }
    }
    cout << Count;
    return 0;
}