#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int max = 0, max_i = 0, s = 0;
    for (int i = 1; i <= 5; i++) 
    {
        int score = 0;
        for (int j = 0; j < 4; j++) 
        {
            cin >> s;
            score += s;
        }

        if (score > max) 
        {
            max = score;
            max_i = i;
        }
    }
    cout << max_i << ' ' << max;

    return 0;
}