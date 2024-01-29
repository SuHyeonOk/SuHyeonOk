#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    string str = "";
    set<string> s;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        s.insert(str);
    }

    vector<string> vec;
    for (int i = 0; i < M; i++)
    {
        cin >> str;

        set<string>::iterator it = s.find(str);
        if (it != s.end()) // 같은 값 있음
        {
            vec.push_back(it->c_str());
        }
    }

    size_t size = vec.size();
    cout << size << '\n';
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < size; i++)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}