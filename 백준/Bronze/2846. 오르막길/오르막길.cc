#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n = 0;
    cin >> n;
    
    int p[1001];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    int ans = 0;
    int l = 1, r = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (p[i] < p[i + 1])
        {
            r++;
            ans = max(ans, p[r] - p[l]);
        }
        else if (p[i] >= p[i + 1])
        {
            l = i + 1;
            r = i + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
