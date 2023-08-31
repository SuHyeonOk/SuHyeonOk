#include <iostream>
#include <vector>
#include <array>
#include <queue>
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
void BFS(int _x, int _y)
{
    queue<pair<int, int>> q;
    q.push({ _x, _y });

    while (false == q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        for (size_t i = 0; i < MAX; i++)
        {
            int x = qx + dx[i];
            int y = qy + dy[i];

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
            q.push({ x, y });
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;
    vec.resize(M, vector<bool>(N, false));

    // 모든 좌표 입력 받기
    COD cod;
    vector<COD> data(K, { 0, 0, 0, 0 });
    for (int i = 0; i < K; i++)
    {
        cin >> cod.iStartX >> cod.iStartY >> cod.iEndX >> cod.iEndY;
        data[i] = cod;
    }

    // 입력 받은 좌표 채우기
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

    // 영역 개수, 영역의 넓이를 구하기 위해서 방문하지 않은 곳이 있는지 확인
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
                BFS(i, j);
                result.push_back(iCount);
            }
        }
    }

    // 모든 결과를 다 구하고 정리한 다음 출력
    sort(result.begin(), result.end());

    cout << iArea << '\n';
    size = result.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}