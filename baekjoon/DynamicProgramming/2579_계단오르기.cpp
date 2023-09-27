#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/2579

    [ 문제 정리 ]
    1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
    2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
    3. 마지막 도착 계단은 반드시 밟아야 한다.

    각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구한다.


    [ 해결 방법 ]
    n 번째 dp가 될 수 있는 경우는
    * x * *
    * x *       2가지 뿐이다.

    dp[n] = max(dp[n-3] + stair[n-1] + stair[n], dp[n-2] + stair[n])

    dp[0] = 0
    dp[1] = stair[1]
    dp[2] = stair[1] + stair[2]
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3])
    임을 알 수 있다.


    [ 자료형 ]
    계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.
    따라서, 나올 수 있는 최대값은 300 * 10,000 이고, 3,000,000 은 int 범위보다 작으므로
    int 를 사용하여 구현한다.

*/

int stair[301];
int dp[301];

int getMaxScore(int n)
{
    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for (int i = 4; i <= n; ++i)
    {
        dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
    }
    return dp[n];
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    ios::sync_with_stdio(0);

    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i)
    {
        int score;
        cin >> score;
        stair[i] = score;
    }
    cout << getMaxScore(count);
}