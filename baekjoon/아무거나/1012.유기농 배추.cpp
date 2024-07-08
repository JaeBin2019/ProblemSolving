#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

/*

    https://www.acmicpc.net/problem/1012

    [ 문제 정리 ]


    [ 해결 방법 ]

    [ 자료형 ]
    M : 배추밭 가로 길이
    1 <= M <= 50
    N : 배추밭 세로 길이
    1 <= N <= 50

    K : 배추 개수
    1 <= K <= 2500

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초


*/

int visited[51][51];
pair<int, int> direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int M, N, K;

void dfs(int i, int j)
{
    stack<pair<int, int>> st;
    st.push({i, j});

    while (!st.empty())
    {
        pair<int, int> top = st.top();
        st.pop();

        int x = top.first;
        int y = top.second;
        visited[y][x] = 0;

        for (int i = 0; i < 4; ++i)
        {
            int moveX = x + direction[i].first;
            int moveY = y + direction[i].second;
            if (moveX >= 0 && moveX < M && moveY >= 0 && moveY < N)
            {
                if (visited[moveY][moveX] == 1)
                {
                    st.push({moveX, moveY});
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int testCount;
    cin >> testCount;

    while (testCount--)
    {
        int answer = 0;
        memset(visited, 0, sizeof(visited));
        cin >> M >> N >> K;
        stack<int> st;

        for (int i = 0; i < K; ++i)
        {
            int x, y;
            cin >> x >> y;
            visited[y][x] = 1;
        }

        for (int j = 0; j < N; ++j)
        {
            for (int i = 0; i < M; ++i)
            {
                if (visited[j][i] == 1)
                {
                    dfs(i, j);
                    ++answer;
                }
            }
        }

        cout << answer << '\n';
    }
}