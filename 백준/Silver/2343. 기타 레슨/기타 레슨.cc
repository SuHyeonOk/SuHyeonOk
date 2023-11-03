#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

int arr[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 }, M{ 0 }, sum{ 0 }, arrMax{ 0 };
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        arrMax = max(arrMax, arr[i]);
    }

    int left{ arrMax }, right{ sum };

    while (left <= right)
    {
        int mid = (left + right) * 0.5;
        int tempSum{ 0 }, tempM{ 0 };

        for (int i = 0; i < N; i++)
        {
            if (tempSum + arr[i] > mid)
            {
                tempSum = 0;
                ++tempM;
            }
            tempSum += arr[i];
        }

        if (tempSum != 0)
        {
            ++tempM;
        }

        if (tempM <= M)
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