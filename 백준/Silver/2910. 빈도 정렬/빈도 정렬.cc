#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, pair<int, int>> Input, pair<int, pair<int, int>> b)
{
    // 만약 숫자가 같을 때는 입력 받은 순서로 정렬
    if (Input.second.first == b.second.first)
    {
        return Input.second.second < b.second.second;
    }

    // 기본적으로 같은 개수 기준으로 정렬
    return Input.second.first > b.second.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, C = 0;
    cin >> N >> C;

    // map<숫자, pair<같은 개수, 입력 받은 순서>>
    map<int, pair<int, int>> m;

    int Input = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> Input;

        if (m.find(Input) == m.end())
        {
            m[Input] = { 1, i };
        }
        else
        {
            m[Input].first++;
        }
    }

    // Compare() 함수로 정렬하기 위해서 map → vector
    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), Compare);

    for (auto at : v)
    {
        for (int i = 0; i < at.second.first; i++)
        {
            cout << at.first << " ";
        }
    }

    return 0;
}