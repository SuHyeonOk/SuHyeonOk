#include <iostream>
using namespace std;

int main() 
{
    int n = 0,ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        
        if (p != i)
        {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}