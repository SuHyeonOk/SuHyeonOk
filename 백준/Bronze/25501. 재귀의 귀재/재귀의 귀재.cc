#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int g_count{ 0 };

int recursion(const char* s, int l, int r) 
{
    ++g_count;
    
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) 
{
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T{ 0 }, temp{ 0 };
    cin >> T;

    char S[1001];
    while (T--)
    {
        cin >> S;

        temp = isPalindrome(S);
        cout << temp << " " << g_count << '\n';
        g_count = 0;
    }

    return 0;
}