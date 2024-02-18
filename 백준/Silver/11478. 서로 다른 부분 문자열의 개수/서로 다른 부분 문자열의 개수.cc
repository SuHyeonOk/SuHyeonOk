#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S = "";
    cin >> S;
    
    set<string> set;
    string Str = "";
    size_t Size = S.size();
    for (size_t i = 0; i < Size; i++)
    {
        for (size_t j = i; j < Size; j++)
        {
            Str += S[j];
            set.insert(Str); // 중복 값을 저장하지 않는 set
        }
        Str = "";
    }

    cout << set.size();

    return 0;
}