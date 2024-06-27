#include <iostream>
#include <algorithm>

using namespace std;

/*

    4-2. 왕실의 나이트

    [ 문제 정리 ]
    체스판 8 X 8 좌표평면에서 나이트가 이동할 수 있는 경우의 수를 출력한다
    나이트는 일반 체스 게임과 똑같이 아래와 같은 방식으로 움직인다

     1. 수평으로 2칸 이동 후 수직으로 1칸 이동
     2. 수직으로 2칸 이동 후 수평으로 1칸 이동

    행은 1 ~ 8, 열은 a ~ h 로 표현한다
    나이트의 위치는 a1 처럼 열과 행으로 주어진다


    [ 해결 방법 ]
    move 를 정의해두고, 움직인 뒤의 나이트 위치가 체스판 안에 있는지 체크한다


    [ 자료형 ]
    int 로 충분하다


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
    O(8)


*/
int main()
{
    int answer = 0;
    string position;
    cin >> position;

    int row, col;
    row = position[0] - 'a';
    col = position[1] - '1';

    pair<int, int> move[8] = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

    for (int i = 0; i < 8; ++i)
    {
        if (row + move[i].first >= 0 && row + move[i].first < 8 && col + move[i].second >= 0 && move[i].second < 8)
            ++answer;
    }

    cout << answer;
}
