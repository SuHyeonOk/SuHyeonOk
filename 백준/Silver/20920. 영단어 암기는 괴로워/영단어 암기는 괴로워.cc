#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    if (a.first.length() != b.first.length())
    {
        return a.first.length() > b.first.length();
    }
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    string Input = "";
    map<string, int> m;
    for (int i = 0; i < N; i++)
    {
        cin >> Input;

        if (Input.length() < M)
        {
            continue;
        }

        map<string, int>::iterator Temp = m.find(Input);
        if (m.end() != Temp)
        {
            ++Temp->second;
        }
        else
        {
            m.insert({ Input, 1 });
        }
    }

    // Compare을 기준으로 정렬하기 위해 vector로 변환
    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), Compare);

    string Temp = "";
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (Temp != it->first)
        {
            cout << it->first << '\n';
            Temp = it->first; // 이전에 출력했던 값을 다시 출력하지 않기 위해 저장
        }
    }

    return 0;
}
