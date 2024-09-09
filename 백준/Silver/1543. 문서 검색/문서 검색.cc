#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Document = "", Word = "";
    getline(cin, Document);
    getline(cin, Word);

    size_t DocumentSize = Document.size();
    size_t WordSize = Word.size();

    int Result = 0;
    for (size_t i = 0; i < DocumentSize;)
    {
        string Temp = Document.substr(i, WordSize);
        if (Word == Temp)
        {
            ++Result;
            i += WordSize;
        }
        else
        {
            ++i;
        }
    }

    cout << Result;

    return 0;
}