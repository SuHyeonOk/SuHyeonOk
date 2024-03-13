#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;
    
    int Count = 0;
    string Input = "";
    set<string> Ss;
    while (N--)
    {
        cin >> Input;

        if (Input == "ENTER")
        {
            Ss.clear();
            continue;
        }

        if (Ss.end() == Ss.find(Input))
        {
            ++Count;
            Ss.emplace(Input);
        }
    }

    cout << Count;

    return 0;
}