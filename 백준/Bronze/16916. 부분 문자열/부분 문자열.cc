#include <iostream>
#include <vector>
using namespace std;

// P의 접두사 테이블을 계산하는 함수
vector<int> makeLPS(const string& P)
{
    int m = P.size();
    vector<int> lps(m, 0);
    int j = 0;

    for (int i = 1; i < m; ++i)
    {
        while (j > 0 && P[i] != P[j])
        {
            j = lps[j - 1];
        }

        if (P[i] == P[j])
        {
            lps[i] = ++j;
        }
    }

    return lps;
}

// KMP 알고리즘으로 문자열 매칭을 찾는 함수
bool KMP(const string& S, const string& P)
{
    vector<int> lps = makeLPS(P);
    int n = S.size();
    int m = P.size();
    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && S[i] != P[j])
        {
            j = lps[j - 1];
        }

        if (S[i] == P[j])
        {
            if (j == m - 1)
            {
                return true;  // 패턴을 찾음
            }

            ++j;
        }
    }

    return false;  // 패턴을 찾지 못함
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S, P;
    cin >> S >> P;

    if (KMP(S, P) == true)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
