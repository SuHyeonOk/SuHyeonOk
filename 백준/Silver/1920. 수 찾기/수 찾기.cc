#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n{ 0 };
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int m{ 0 };
    cin >> m;

    vector<int> M(m);
    for (int i = 0; i < m; i++)
    {
        cin >> M[i];
    }

    bool find{ false };
    int left{ 0 }, right{ n - 1 }, mid{ 0 }, target{ 0 };
    for (int i = 0; i < m; i++)
    {
        find = false;
        left = 0;
        right = n - 1;
        mid = 0;
        target = M[i];

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (target == A[mid])
            {
                find = true;
                break;
            }
            else if (target < A[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (true == find)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}