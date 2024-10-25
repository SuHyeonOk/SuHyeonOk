#include <iostream>
#include <vector>
using namespace std;

int N, L;
vector<vector<int>> Map;

bool CheckPath(vector<int>& Path)
{
    vector<bool> Used(N, false);
    for (int i = 0; i < N - 1; i++)
    {
        if (Path[i] == Path[i + 1])
        {
            continue;
        }
        if (abs(Path[i] - Path[i + 1]) > 1)
        {
            return false;
        }
        if (Path[i] > Path[i + 1])
        {
            for (int j = i + 1; j <= i + L; j++)
            {
                if (j >= N || Path[j] != Path[i + 1] || Used[j])
                {
                    return false;
                }
                Used[j] = true;
            }
        }
        else
        {
            for (int j = i; j > i - L; j--)
            {
                if (j < 0 || Path[j] != Path[i] || Used[j])
                {
                    return false;
                }
                Used[j] = true;
            }
        }
    }
    return true;
}

int main()
{
    cin >> N >> L;
    Map = vector<vector<int>>(N, vector<int>(N));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Map[i][j];
        }
    }
    
    int Result = 0;
    
    for (int i = 0; i < N; i++)
    {
        vector<int> RowPath = Map[i];
        vector<int> ColPath(N);
        for (int j = 0; j < N; j++)
        {
            ColPath[j] = Map[j][i];
        }
        
        if (CheckPath(RowPath))
        {
            Result++;
        }
        if (CheckPath(ColPath))
        {
            Result++;
        }
    }
    
    cout << Result << endl;
    return 0;
}