#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compareIgnoreCase(const string& a, const string& b)
{
    string lowerA = a, lowerB = b;
    transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
    transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
    return lowerA < lowerB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;

    while (true)
    {
        cin >> N;
        if (N == 0) break;

        vector<string> words(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> words[i];
        }

        sort(words.begin(), words.end(), compareIgnoreCase);
        cout << words[0] << '\n';
    }

    return 0;
}
