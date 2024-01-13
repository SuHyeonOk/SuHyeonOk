#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A{ 0 }, B{ 0 };
    cin >> A >> B;

    int input{ 0 };
    set<int> s;
    for (int i = 0; i < A; i++)
    {
        cin >> input;
        s.insert(input);
    }

    int Symmetry{ 0 };
    for (int i = 0; i < B; i++)
    {
        cin >> input;
        set<int>::iterator it = s.find(input);

        if (it != s.end()) // 이미 있는 경우
        {
            ++Symmetry;
        }
    }

    cout << (A - Symmetry) + (B - Symmetry);


    return 0;
}