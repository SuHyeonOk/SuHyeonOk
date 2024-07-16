#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a = "", b = "";
    char oper = ' ';
    cin >> a >> oper >> b;

    int ALength = a.length();
    int BLength = b.length();

    if (oper == '+')
    {
        if (ALength >= BLength)
        {
            a[ALength - BLength] = a[ALength - BLength] + 1;
            cout << a;
        }
        else
        {
            b[BLength - ALength] = '1';
            cout << b;
        }
    }
    else
    {
        for (int i = 1; i < BLength; ++i)
        {
            a += '0';
        }
        cout << a;
    }

    return 0;
}