#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n{ 0 }, count{ 0 };

    while (cin >> n)
    {
        if (cin.eof() == true)
        {
            break;
        }

        if (n > 0)
        {
            ++count;
        }
    }

    cout << count;

    return 0;
}