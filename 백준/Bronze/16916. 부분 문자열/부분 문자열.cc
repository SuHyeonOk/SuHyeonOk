#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Str = "", Temp = "";
    cin >> Str >> Temp;

    if (strstr(Str.c_str(), Temp.c_str()) != NULL) 
    {
        cout << 1;
    }
    else 
    {
        cout << 0;
    }

    return 0;
}