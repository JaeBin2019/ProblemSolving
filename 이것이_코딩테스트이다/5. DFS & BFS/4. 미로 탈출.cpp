#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*

    5-4. 미로 탈출

    [ 문제 정리 ]
    N X M 크기의 미로가 있다. 0은 벽, 1은 길을 의미하며,
    미로를 탈출하기 위해 필요한 최소 칸의 수를 알아내라.
    시작칸은 (1,1) 이고 출구는 (N,M) 에 위치해있다
    N 세로, M 가로

    [ 해결 방법 ]
    탈출하는 데 필요한 최소한의 거리이기 때문에, BFS 로 탐색한다


    [ 자료형 ]
    4 <= N, M <= 200

    5 6
    101010
    111111
    000001
    111111
    111111

    answer : 10

    6 6
    101010
    111111
    000001
    111111
    100010
    111111

    answer : 13


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

int N, M;
int maze[1000][1000];

pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs()
{
    queue<pair<int, int>> q;

    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> position = q.front();
        int row = position.first;
        int col = position.second;
        q.pop();

        if (row == M - 1 && col == N - 1)
        {
            return maze[N - 1][M - 1];
        }

        for (int i = 0; i < 4; ++i)
        {
            int movedRow = row + direction[i].first;
            int movedCol = col + direction[i].second;

            if (movedRow < 0 || movedRow >= M || movedCol < 0 || movedCol >= N)
                continue;

            if (maze[movedCol][movedRow] == 1)
            {
                maze[movedCol][movedRow] = maze[col][row] + 1;
                q.push({movedRow, movedCol});
            }
        }
    }
    return 0;
}

int main()
{
    int answer;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            // 1%d : 1자리 정수만을 읽어옴
            scanf("%1d", &maze[i][j]);
        }
    }

    answer = bfs();

    cout << answer;
}
