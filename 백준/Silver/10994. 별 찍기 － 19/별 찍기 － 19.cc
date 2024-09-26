#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    cin >> n;

    auto size{ 4 * n - 3 };
    vector<string> stars(size, string(size, ' '));

    for (int k = 1; k <= n; ++k) 
    {
        int b = 2 * (n - k);
        int e = size - 1 - b;

        for (int i = 0; i < 4 * k - 3; ++i) 
        {
            stars[b][b + i] = stars[b + i][b] = '*';
            stars[e][b + i] = stars[b + i][e] = '*';
        }
    }

    for (const auto& s : stars) 
    {
        cout << s << '\n';
    }
}