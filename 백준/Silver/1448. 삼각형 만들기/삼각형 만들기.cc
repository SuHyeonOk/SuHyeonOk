#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, input = 0;
    cin >> N;

    vector<int> vec;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end(), greater<>());

    int i = 0;
    while (true)
    {
        if (vec[i] < vec[i + 1] + vec[i + 2]) 
        {
            cout << vec[i] + vec[i + 1] + vec[i + 2] << '\n';
            break;
        }

        i++;

        if (i + 2 >= N) 
        {
            cout << -1 << '\n';
            break;
        }
    }

    return 0;
}