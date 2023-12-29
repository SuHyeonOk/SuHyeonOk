#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 3000000000
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    long long min = 3000000000;
    vector<long long>result(3);

    for (int i = 0; i < n - 2; i++) 
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right) 
        {
            long long sum = vec[i] + vec[left] + vec[right];

            if (abs(sum) < min)
            {
                min = abs(sum);
                result[0] = vec[i];
                result[1] = vec[left];
                result[2] = vec[right];
            }

            if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << result[0] << " " << result[1] << " " << result[2];

    return 0;
}