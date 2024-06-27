#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*

    https://school.programmers.co.kr/learn/courses/30/lessons/42860

    [ 문제 정리 ]
    조이스틱을 움직여서 A로만 이루어져 있는 문자를 입력받은 name 의 문자열로 바꾼다.
    필요한 움직임의 최소값을 구하여라.

    ▲ - 다음 알파벳
    ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
    ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
    ▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)


    [ 해결 방법 ]
    조이스틱을 위아래로 움직이는 경우, min(name[i] - 'A', 'Z' - name[i] + 1)을 통해
    최소한의 움직임으로 원하는 알파벳을 만들 수 있다
    알파벳이 A가 많은 경우, 좌우 움직임의 최소값은 다음과 같이 4가지 경우가 있다
    A가 아닌 값을 vector에 저장하여, 현재 A가 아닌 값과 다음 A가 아닌 값을 이동하며 최소값를 계산한다

    AABAACAADA

    1. 왼쪽에서 오른쪽 끝까지           position[position.size() - 1]
    2. 오른쪽에서 왼쪽 끝까지           (int)name.length() - position[0]
    3. 왼쪽 -> 제자리 -> 오른쪽         2 * position[i] + name.length() - position[i+1]
    4. 오른쪽 -> 제자리 -> 왼쪽         position[i] + 2 * (name.length() - position[i+1])

    계산이 끝나면, 조이스틱을 위아래로 움직인 횟수에 좌우로 움직인 횟수를 더한다.

    [ 자료형 ]
    1 <= name length <= 20

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

int solution(string name)
{
    int answer = 0, minMove = 280;
    vector<int> position;

    for (int i = 0; i < name.length(); ++i)
    {
        if (name[i] != 'A')
        {
            answer += min(name[i] - 'A', 'Z' - name[i] + 1);
            position.push_back(i);
        }
    }

    // 모든 값이 A로 이루어진 문자열이다
    if (position.empty())
        return 0;

    // 왼쪽에서 오른쪽 끝까지, 오른쪽에서 왼쪽 끝까지
    minMove = min(position[position.size() - 1], (int)name.length() - position[0]);

    for (int i = 0; i < position.size() - 1; ++i)
    {
        // 왼쪽 -> 제자리 -> 오른쪽
        int startLeft = 2 * position[i] + name.length() - position[i + 1];
        // 오른쪽 -> 제자리 -> 왼쪽
        int startRight = position[i] + 2 * (name.length() - position[i + 1]);

        minMove = min(minMove, min(startLeft, startRight));
    }

    answer += minMove;

    return answer;
}