#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A{ 0 }, B{ 0 };
    cin >> A >> B;

    int input{ 0 };
    map<int, bool> m;
    for (int i = 0; i < A; i++)
    {
        cin >> input;
        m.emplace(input, false);
    }

    int Symmetry{ 0 };
    for (int i = 0; i < B; i++)
    {
        cin >> input;
        map<int, bool>::iterator it = m.find(input);

        if (it == m.end()) // 없다.
        {
            m.emplace(input, false);
        }
        else // 있다.
        {
            ++Symmetry;
            m[input] = true;
        }
    }

    cout << (A - Symmetry) + (B - Symmetry);


    return 0;
}