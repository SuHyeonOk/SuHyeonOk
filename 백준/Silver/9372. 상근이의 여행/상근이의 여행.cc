#include <iostream>
using namespace std;

int main() 
{
    int T{ 0 }, N{ 0 }, M{ 0 }, a{ 0 }, b{ 0 };
    cin >> T;

    while (T--) 
    {
        cin >> N >> M;

        while (M--) 
        {
            cin >> a >> b;
        }

        cout << N - 1 << endl;
    }

}