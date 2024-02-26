#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1 = "", str2 = "";
    cin >> str1 >> str2;

    int cnt = 0;
    int cnt1 = 0;

    int lengthStr1 = str1.length();
    int lengthStr2 = str2.length();
    for (int i = 0; i < lengthStr1; i++)
    {
        if (str1[i] == 'a') 
        {
            cnt++;
        }
    }

    for (int i = 0; i < lengthStr2; i++)
    {
        if (str2[i] == 'a') 
        {
            cnt1++;
        }
    }

    if (cnt >= cnt1 || lengthStr1 == lengthStr2)
    {
        cout << "go";
    }
    else 
    {
        cout << "no";
    }

    return 0;
}
