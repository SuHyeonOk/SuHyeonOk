#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    size_t n{ 0 }, m{ 0 };
    cin >> n >> m;

    size_t sum{ n + m };
    vector<int> vec(sum);
    for (size_t i = 0; i < sum; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for (size_t i = 0; i < sum; i++)
    {
        cout << vec[i] << ' ';
    }

    return 0;
}