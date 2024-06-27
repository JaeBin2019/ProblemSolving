#include <iostream>
#include <algorithm>

using namespace std;

/*

    4-3. 게임 개발

    [ 문제 정리 ]
    N X M 의 직사각형에서 캐릭터를 다음과 같은 규칙대로 움직인다.
    1. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 갈 곳을 정한다
    2. 캐릭터의 바로 왼쪽 방향에 아직 가보지 않은 칸이 존재한다면, 왼쪽 방향으로 회전한 다음 왼쪽으로 1칸을 전진한다.
      왼쪽 방향에 가보지 않은 칸이 없다면, 왼쪽 방향으로 회전만 수행하고 1단계로 돌아간다
    3. 만약 네 방향 모두 가본 칸이거나 바다로 되어 있는 칸인 경우에는, 바라보는 방향을 유지한 채로 1칸 뒤로 가고
      1단계로 돌아간다. 단, 이때 뒤쪽 방향이 바다인 칸이라 뒤로 갈 수 없는 경우에는 움직임을 멈춘다.

    이때, 캐릭터가 방문한 칸의 수를 출력하여라.

    입력 예시

    4 4
    1 1 0
    1 1 1 1
    1 0 0 1
    1 1 0 1
    1 1 1 1

    답 : 3

    4 4
    1 1 0
    1 1 1 1
    1 0 0 0
    1 1 0 0
    1 1 1 0

    답 : 6


    [ 해결 방법 ]
    조건을 있는 그대로 구현한다
    방문한 곳은 2로 바꾸어, 바다와 방문한 곳을 구별한다


    [ 자료형 ]
    3 <= N, M <= 50
    int 사용


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초



*/

int N, M;
int map[51][51];

// 북, 동, 남, 서
pair<int, int> step[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 왼쪽으로 회전
void turnLeft(int &direction)
{
    direction = (direction - 1 + 4) % 4;
}

int moveValid(pair<int, int> position, int direction)
{
    int row = position.first + step[direction].first;
    int col = position.second + step[direction].second;

    if (row < 0 || row >= N || col < 0 || col >= M || map[col][row] == 1)
        return -1;

    if (map[col][row] == 2)
        return 1;

    return 0;
}

int moveLeftValid(pair<int, int> position, int direction)
{
    turnLeft(direction);

    return moveValid(position, direction);
}

void moveStraight(pair<int, int> &position, int direction)
{
    position.first += step[direction].first;
    position.second += step[direction].second;
}

bool isVisitedAll(pair<int, int> position)
{
    for (int i = 0; i < 4; ++i)
    {
        if (moveValid(position, i) == 0)
            return false;
    }
    return true;
}

int main()
{
    int answer = 0;

    pair<int, int> position;
    int direction;

    cin >> N >> M;
    cin >> position.first >> position.second >> direction;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];

    // 시작점은 방문하고 시작하므로, 방문처리하여 값을 2로 바꾼다
    map[position.second][position.first] = 2;
    ++answer;

    while (1)
    {
        // 왼쪽으로 갈 수 있다면, 왼쪽으로 돌고
        // 그 방향으로 직진하고, 그 위치를 방문처리한다
        if (moveLeftValid(position, direction) == 0)
        {
            turnLeft(direction);
            moveStraight(position, direction);
            map[position.second][position.first] = 2;
            ++answer;
        }

        // 왼쪽으로 갈 수 없지만, 주변 모든 곳을 방문한 것이 아니라면
        // 왼쪽으로 돌기만 한다
        else if (!isVisitedAll(position))
        {
            turnLeft(direction);
        }

        // 모두 방문했다면, 내 뒷방향이 바다가 아닌지 체크하고
        // 바다가 아니라면, 뒤로 한 칸 직진하고
        // 바다라면 멈춘다
        else
        {
            int back = (direction + 2) % 4;
            if (moveValid(position, back) == 1)
                moveStraight(position, back);

            else
                break;
        }
    }

    cout << answer;
}
