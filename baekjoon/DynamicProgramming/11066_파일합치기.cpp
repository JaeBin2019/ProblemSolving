#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/11066

    [ 문제 정리 ]
    파일들을 하나씩 합쳐 임시파일을 만들 때, 비용의 합이 최소가 되도록 한다.
    비용 계산은 합쳐진 파일의 크기로 계산한다.

    40 30 30 50 이 있을때,
    (1,2) -> (1,2), (3,4) -> (1,2,3,4) => (40+30) + (30+50) + (40+30+30+50) = 70 + 80 + 150 = 300
    (1,2) -> (1,2,3) -> (1,2,3,4) => (40+30) + (40+30+30) + (40+30+30+50) = 70 + 100 + 150 = 320

    으로 방식에 따라 값이 달라질 수 있다는 것을 알 수 있다.


    [ 해결 방법 ]
    2차원 dp[i][j]를 선언한다
    이는 i부터 j까지 파일을 합쳤을 시의 비용이다

    i ~ j 까지 파일을 합하는 과정에서 파일들은 특정 지점 m에서 나누어졌을 것이다
    그렇다면, dp[i][j] = dp[i][m] + dp[m+1][j] + sum[i][j] 가 된다.
    sum[i][j]가 추가되는 이유는 각 그룹을 합칠때, 두 그룹의 총 합을 더해주어야 하기 때문이다

    여기서 dp[i][j] 값이 최소가 되는 m 값을 찾으면 된다


    [ 자료형 ]
    양의 정수 K (3 ≤ K ≤ 500) 이므로 int를 사용한다

    [ 시간 복잡도 ]
    O(K^3) = O(500^3) = O(125,000,000) 이다


*/

#define INF 1000000000
int dp[501][501];
int sum[501];
int file[501];

int minCost(int fileCount)
{
    for (int i = 1; i <= fileCount; ++i)
    {
        cin >> file[i];
        sum[i] = sum[i - 1] + file[i];
    }
    for (int i = 1; i <= fileCount; ++i)
    {
        for (int j = 1; j <= fileCount - i; ++j)
        {
            dp[j][i + j] = INF;
            for (int k = j; k < i + j; ++k)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
            }
        }
    }
    return dp[1][fileCount];
}

int main()
{
    std::cout.tie(0);
    ios::sync_with_stdio(0);

    int chapterCount;
    cin >> chapterCount;

    for (int i = 0; i < chapterCount; ++i)
    {
        int fileCount;
        cin >> fileCount;

        cout << minCost(fileCount) << '\n';
    }
}