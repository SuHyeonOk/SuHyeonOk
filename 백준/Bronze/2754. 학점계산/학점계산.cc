#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str{ "" }, print{ "" };
    cin >> str;

    if (str == "A+")
    {
        print = "4.3";
        cout << print;
    }
    else if (str == "A0")
    {
        print = "4.0";
        cout << print;
    }
    else if (str == "A-")
    {
        print = "3.7";
        cout << print;
    }
    else if (str == "B+")
    {
        print = "3.3";
        cout << print;
    }
    else if (str == "B0")
    {
        print = "3.0";
        cout << print;
    }
    else if (str == "B-")
    {
        print = "2.7";
        cout << print;
    }
    else if (str == "C+")
    {
        print = "2.3";
        cout << print;
    }
    else if (str == "C0")
    {
        print = "2.0";
        cout << print;
    }
    else if (str == "C-")
    {
        print = "1.7";
        cout << print;
    }
    else if (str == "D+")
    {
        print = "1.3";
        cout << print;
    }
    else if (str == "D0")
    {
        print = "1.0";
        cout << print;
    }
    else if (str == "D-")
    {
        print = "0.7";
        cout << print;
    }
    else
    {
        print = "0.0";
        cout << print;
    }

    return 0;
}