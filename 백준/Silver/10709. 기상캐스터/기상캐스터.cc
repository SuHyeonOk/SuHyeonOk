#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int h = 0, w = 0;
    cin >> h >> w;

    vector<char> vec; 
    for (int i = 0; i < h; i++)
    {
        bool find = false;
        int num = 1;

        for (int j = 0; j < w; j++)
        {
            char ch = ' ';
            cin >> ch;
            vec.push_back(ch);
        }

        for (int j = 0; j < w; j++)
        {
            if (vec[j] == 'c')
            {
                find = true;
                num = 1;
                cout << "0 ";
            }

            if (false == find && vec[j] == '.')
            {
                cout << "-1 ";
            }

            if (find && vec[j] == '.')
            {
                cout << num++ << " ";
            }
        }

        cout << '\n';
        vec.clear();
    }

    return 0;
}