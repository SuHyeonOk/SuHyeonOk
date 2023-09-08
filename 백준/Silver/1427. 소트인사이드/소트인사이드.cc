#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string N{ 0 };
    cin >> N;

    vector<int> vec;
    size_t length = N.length();
    for (size_t i = 0; i < length; i++)
    {
        vec.push_back(N[i] - '0');
    }

    sort(vec.rbegin(), vec.rend());

    for (size_t i = 0; i < length; i++)
    {
        cout << vec[i];
    }

    return 0;
}