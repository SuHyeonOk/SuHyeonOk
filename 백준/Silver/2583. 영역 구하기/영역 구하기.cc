#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

#define MAX 4

int M{ 0 }, N{ 0 }, K{ 0 }, iCount{ 0 };
vector<vector<bool>> vec;

typedef  struct Coordinate
{
    int iStartX{ 0 }, iStartY{ 0 }, iEndX{ 0 }, iEndY{ 0 };

}COD;

array<int, MAX> dx{ 0, 0, -1, 1 }, dy{ -1, 1, 0,0 };
void DFS(int _x, int _y)
{
    for (size_t i = 0; i < MAX; i++)
    {
        int x = _x + dx[i];
        int y = _y + dy[i];

        if (x < 0 || x >= M || y < 0 || y >= N)
        {
            continue;
        }

        if (vec[x][y] == true)
        {
            continue;
        }

        vec[x][y] = true;
        ++iCount;
        DFS(x, y);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;
    vec.resize(M, vector<bool>(N, false));

    COD cod;
    vector<COD> data(K, { 0, 0, 0, 0 });
    for (int i = 0; i < K; i++)
    {
        cin >> cod.iStartX >> cod.iStartY >> cod.iEndX >> cod.iEndY;
        data[i] = cod;
    }

    size_t size = data.size();
    for (size_t k = 0; k < size; k++)
    {
        for (int i = data[k].iStartY; i < data[k].iEndY; i++)
        {
            for (int j = data[k].iStartX; j < data[k].iEndX; j++)
            {
                vec[i][j] = true;
            }
        }
    }

    int iArea{ 0 };
    vector<int> result;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (false == vec[i][j])
            {
                ++iArea;
                vec[i][j] = true;
                iCount = 1;
                DFS(i, j);
                result.push_back(iCount);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << iArea << '\n';
    size = result.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}