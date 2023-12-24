#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s{ "" };
    cin >> s;

    vector<string>vec;
    size_t size{ s.size() };
    string temp{ "" };
    temp.resize(size);

    for (size_t i = 0; i < size; i++)
    {
        string temp = s.substr(i, size);;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    for (size_t i = 0; i < size; i++)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}