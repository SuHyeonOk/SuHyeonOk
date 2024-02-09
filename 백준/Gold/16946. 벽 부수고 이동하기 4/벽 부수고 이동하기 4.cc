#include <iostream>
#include <vector>
using namespace std;

int n, m;
int tmp;
int mark = 1;
vector <vector <int>> v;
vector <int> loc;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int visit[1001][1001] = { 0 };

void DFS(int x, int y, int cur_mark)
{
    visit[x][y] = cur_mark;
    tmp++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m)
        {
            if (visit[nx][ny] == 0 && v[nx][ny] == 0)
            {
                DFS(nx, ny, cur_mark);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    string x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = x[j] - '0';
        }
    }
    loc.push_back(-1);

    // 인덱스 번호를 맞춰주기 위해 가장 앞에 버리는 값을 저장.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0 && visit[i][j] == 0)
            {
                tmp = 0;
                DFS(i, j, mark);
                loc.push_back(tmp);
                mark++;
            }
        }
    }

    bool* chk_loc = new bool[loc.size()] {false};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        if (!chk_loc[visit[nx][ny]] && v[nx][ny] == 0)
                        {
                            v[i][j] += loc[visit[nx][ny]];
                            chk_loc[visit[nx][ny]] = true;
                        }
                    }
                }
                fill_n(chk_loc, loc.size(), false);
            }
            cout << v[i][j] % 10;
        }
        cout << "\n";
    }

    return 0;
}