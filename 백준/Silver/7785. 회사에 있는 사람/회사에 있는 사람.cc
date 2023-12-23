#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; 
    cin >> n;

    map<string, string, greater<>> m;
    for (int i = 0; i < n; i++)
    {
        string name, EorL;

        cin >> name >> EorL;
        m[name] = EorL;
    }

    map<string, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++) 
    {
        if (it->second == "enter") 
        {
            cout << it->first << "\n";
        }
    }

    return 0;
}