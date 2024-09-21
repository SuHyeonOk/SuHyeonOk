#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Count = 0;
    while (true)
    {
        int L = 0, P = 0, V = 0;
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
        {
            break;
        }

        ++Count;
        cout << "Case " << Count << ": " << ((V / P) * L) +  min((V % P) , L)<< '\n';
    }

    return 0;
}