#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;
#define MAX 1

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string N{ "" };
    cin >> N;

    vector<int> vec;
    int sum{ 0 };
    size_t size = N.size();
    for (size_t i = 0; i < size; i++)
    {
        vec.push_back(N[i] - '0');
        sum += vec[i];
    }

    sort(vec.rbegin(), vec.rend());

    if (sum % 3 == 0 && vec[size - 1] == 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << vec[i];
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}