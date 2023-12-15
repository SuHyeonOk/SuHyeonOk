#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n{ 0 }, m{ 0 };
    cin >> n >> m;

    vector<int> vec(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    long long left{ 1 }, right{ vec[n - 1] * m }, mid{ 0 }, count{ 0 };

    while (left <= right)
    {
        mid = (left + right) / 2;
        count = 0;

        for (long long i = 0; i < n; i++)
        {
            count += mid / vec[i];

            if (count > m)
            {
                break;
            }
        }

        if (count >= m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}