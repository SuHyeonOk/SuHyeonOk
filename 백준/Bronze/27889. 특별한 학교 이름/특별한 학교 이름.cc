#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Input = "";
    cin >> Input;

    if (Input == "NLCS")
    {
        cout << "North London Collegiate School";
    }
    else if (Input == "BHA")
    {
        cout << "Branksome Hall Asia";
    }
    else if (Input == "KIS")
    {
        cout << "Korea International School";
    }
    else if (Input == "SJA")
    {
        cout << "St. Johnsbury Academy";
    }

    return 0;
}