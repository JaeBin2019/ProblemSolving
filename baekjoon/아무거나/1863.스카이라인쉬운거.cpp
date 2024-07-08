#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/1863

    [ 문제 정리 ]
    건물의 스카이라인이 바뀌는 부분의 좌표가 주어진다
    가장 최소가 되는 건물 개수를 구하여라


    [ 해결 방법 ]
    먼저, Stack 에 0 을 넣는다

    1. 이전보다 더 높은 좌표가 나오면 새 건물이라는 의미이므로 Stack 에 넣는다

    2. Stack 의 top 보다 낮은 y 좌표가 나오면 Stack 에 있던 건물들의 끝부분을 찾았다는 의미이므로,
     top 보다 낮은 동안 계속해서 더 높은 건물들을 Stack에서 빼내고, answer 을 추가한다

    3. Stack 의 top 이 현재 y 좌표와 같다면, 그냥 넘어가고
     top 보다 y 좌표가 크다면, 새로운 건물이라는 의미이므로 Stack 에 push 한다

    4. Stack 의 size - 1 (0을 처음에 더했기 때문)
     이 마지막으로 남은 건물들의 개수가 됨으로 이를 answer에 더해준다


    [ 자료형 ]
    N : 좌표 개수
    N <= 50,000

    x, y : 좌표
    1 <= x <= 1,000,000
    0 <= y <= 500,000


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초


*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<pair<int, int>> position
        stack<int>
            yStack;

    int N;
    cin >> N;

    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        position.push_back({x, y});
    }

    sort(position.begin(), position.end());

    yStack.push(0);

    for (int i = 0; i < N; ++i)
    {
        if (yStack.top() < position[i].second)
        {
            yStack.push(position[i].second);
        }
        else if (yStack.top() > position[i].second)
        {
            while (yStack.top() > position[i].second)
            {
                yStack.pop();
                ++answer;
            }
            if (yStack.top() != position[i].second)
            {
                yStack.push(position[i].second);
            }
        }
    }

    answer += yStack.size() - 1;

    cout << answer;
}