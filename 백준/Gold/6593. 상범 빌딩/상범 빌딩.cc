#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int L, R, C;
vector<vector<vector<char>>> vec;
vector<vector<vector<bool>>> visited;
int dl[2]{ -1, 1 };
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

typedef struct tagBuilding
{
    int L = 0, R = 0, C = 0;
    int Time = 0;
}INFO;

int BFS(int SL, int SR, int SC)
{
    queue<INFO> q;
    q.push({ SL, SR, SC, 0 });
    visited[SL][SR][SC] = true;

    while (false == q.empty())
    {
        int CurrentL = q.front().L;
        int CurrentR = q.front().R;
        int CurrentC = q.front().C;
        int CurrentTime = q.front().Time;
        q.pop();

        if ('E' == vec[CurrentL][CurrentR][CurrentC]) // 출구 찾음 종료!
        {
            return CurrentTime;
        }

        for (size_t i = 0; i < 4; i++) // 동 서 남 북
        {
            int NextL = CurrentL;
            int NextR = CurrentR + dx[i];
            int NextC = CurrentC + dy[i];

            if (NextR < 0 || NextR >= R || NextC < 0 || NextC >= C)
            {
                continue;
            }

            if ('#' == vec[NextL][NextR][NextC])
            {
                continue;
            }

            if (true == visited[NextL][NextR][NextC])
            {
                continue;
            }

            visited[NextL][NextR][NextC] = true;
            q.push({ NextL, NextR, NextC, CurrentTime + 1 });
        }

        for (size_t i = 0; i < 2; i++) // 상 하
        {
            int NextL = CurrentL + dl[i];
            int NextR = CurrentR;
            int NextC = CurrentC;
           
            if (NextL < 0 || NextL >= L)
            {
                continue;
            }

            if ('#' == vec[NextL][NextR][NextC])
            {
                continue;
            }

            if (true == visited[NextL][NextR][NextC])
            {
                continue;
            }

            visited[NextL][NextR][NextC] = true;
            q.push({ NextL, NextR, NextC, CurrentTime + 1 });
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true)
    {
        cin >> L >> R >> C; // 층, 행, 열

        if (L == 0 && R == 0 && C == 0) // while문 종료 조건
        {
            break;
        }

        vec.clear();
        vec.resize(L, vector<vector<char>>(R, vector<char>(C, 0)));
        visited.clear();
        visited.resize(L, vector<vector<bool>>(R, vector<bool>(C, false)));

        int StartL = 0, StartR = 0, StartC = 0;
        for (int l = 0; l < L; l++)
        {
            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    cin >> vec[l][r][c];

                    if ('S' == vec[l][r][c])
                    {
                        StartL = l;
                        StartR = r;
                        StartC = c;
                    }
                }
            }
        }

        int Time = BFS(StartL, StartR, StartC);
        if (-1 == Time)
        {
            cout << "Trapped!" << '\n';
        }
        else
        {
            cout << "Escaped in " << Time << " minute(s)." << '\n';
        }
    }

    return 0;
}