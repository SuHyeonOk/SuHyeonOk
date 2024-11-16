#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    string Input = "";
    map<string, int> m;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        string Temp = Input.substr(Input.find('.') + 1);
        ++m[Temp];
    }

    for (auto file : m)
    {
        cout << file.first << ' ' << file.second << '\n';
    }

    return 0;
}