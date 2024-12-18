#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string pq;
    int k;
    cin >> pq >> k;

    int tmp = sqrt(k);
    vector<int>sosu(k + 1, 1);
    for (int i = 2; i <= tmp; i++) 
    {
        if (sosu[i] == 0)
        {
            continue;
        }
        for (int j = i * 2; j <= k; j += i)
        {
            sosu[j] = 0;
        }
    }
    for (int i = 2; i < k; i++)
    {
        if (sosu[i] == 0)
        {
            continue;
        }

        int res = 0;
        int j;
        for (j = 0; j < pq.size(); j++)
        {
            res = ((res * 10) + (pq[j] - '0')) % i;
        }

        if (res == 0) 
        {
            cout << "BAD " << i << "\n";
            return 0;
        }
    }
    cout << "GOOD\n";
    return 0;
}