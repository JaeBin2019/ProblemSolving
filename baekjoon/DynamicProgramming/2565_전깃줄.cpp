#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/2565

    [ 문제 정리 ]
    전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때,
    남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하라. 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.

    [ 해결 방법 ]
    전깃줄이 교차되지 않게 최대한 많이 연결되려면, 이전 연결의 노드값보다 현재 연결의 노드값이 더 큰 경우가 연속되어야 한다.
    9 -> 7 일때, 10 -> 10의 경우, 이전 도착지점 7보다 10으로 더 크기때문에, 추가적으로 연결이 가능하고, 최대 연결 수는 dp[10] = dp[9] + 1이 된다.
    현재 dp 값은 반드시 i 번째 전깃줄을 포함해서 최대로 연결 가능한 값을 찾아야 한다.
    때문에, dp 값은 마지막 노드값을 저장해야하고, i 번째 전깃줄이 연결 가능한 dp값을 찾아 나가야한다.
    최대값은 현재 dp 값을 계산하고, 매번 maxValue를 갱신하는 방법으로 구한다.

    if (dp[i].lastNode > dp[j].lastNode)
        dp[i].count = dp[j].count + 1;

    maxValue = max(maxValue, dp[i].count);

    우리가 원하는 것은 없애야하는 전깃줄 수이므로,
    (전체 전깃줄 - maxValue) 를 반환한다.

    [ 자료형 ]
    전깃줄의 개수 <= 100, 위치의 번호 <= 500
    이므로, int 자료형을 사용한다.

    [ 시간 복잡도 ]
    등차수열로 위치 번호 수만큼 수행하므로, O(n(n+1)/2), O(500(500+1)/2) 이므로
    O(125250) 으로 볼 수 있다.

    => 정렬을 이용해서 수행하면, sorting 시간 + 전깃줄 개수 => O(n * logn) + O(n(n+1)/2)
    = O(100 * log100) + O(100(101)/2) = O(200 + 5050) = O(5250)

    다음 비슷한 문제를 풀 때에는 정렬을 사용하자


*/

class Dp
{
public:
    int count;
    int lastNode;

    Dp()
    {
        count = 1;
        lastNode = 0;
    }
};

Dp dp[501];

int minLine(int num, int last)
{
    int maxValue = 0;
    for (int i = 1; i <= last; ++i)
    {
        // 전깃줄이 연결되지 않은 노드는 무시한다
        if (dp[i].lastNode == 0)
            continue;

        for (int j = 1; j < i; ++j)
        {
            // 전깃줄이 연결되지 않은 노드는 무시한다
            if (dp[j].lastNode == 0)
                continue;

            // 이전 dp의 마지막 노드보다 현재 노드값이 크면, 현재 전깃줄을 이전 dp에 연결한다
            // 따라서, 이전 dp 값에 +1 을 한다
            if (dp[i].lastNode > dp[j].lastNode)
            {
                dp[i].count = max(dp[i].count, dp[j].count + 1);
            }
        }
        maxValue = max(maxValue, dp[i].count);
    }
    return num - maxValue;
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    ios::sync_with_stdio(0);

    int num;
    int last = 0;
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        int node;
        cin >> node;
        cin >> dp[node].lastNode;
        last = max(last, dp[node].lastNode);
    }

    cout << minLine(num, last);
}