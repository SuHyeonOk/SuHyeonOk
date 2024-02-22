#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T = 0, numi = 0;
    string num = "";
    bool flag = false;

    cin >> T;

    while (T--)
    {
        cin >> num;

        numi = stoi(num);
        reverse(num.begin(), num.end());
        numi += stoi(num);
        num = to_string(numi);
        flag = true;

        for (int i = 0; i < num.length() / 2; i++)
        {
            if (num[i] != num[num.length() - 1 - i])
            {
                flag = false;
            }
        }

        if (true == flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
