#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool Standard(const string& _Str1, const string& _Str2)
{
    size_t Size1 = _Str1.size();
    size_t Size2 = _Str2.size();

    if (Size1 == Size2)
    {
        return _Str1 < _Str2;
    }

    return Size1 < Size2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    string Input = "";
    vector<string> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), Standard);
    
    string Temp = "";
    for (int i = 0; i < N; i++)
    {
        if (Temp != vec[i])
        {
            cout << vec[i] << '\n';
            Temp = vec[i];
        }
    }
    
    return 0;
}