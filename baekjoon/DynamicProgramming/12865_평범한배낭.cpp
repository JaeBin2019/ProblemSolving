#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/12865

    [ 문제 정리 ]
     들 수 있는 최대 무게 K 내에서 최대한 가치 있는 것들을 담아
    V 의 합이 최대가 되도록 한다.

    물품 수 : N, 버틸 수 있는 무게 : K, 각 물건의 무게 : W, 각 물건의 가치 : V


    [ 해결 방법 ]
    배낭에 물건을 하나씩 넣으며, 각 경우의 무게를 추가적으로 저장한다.
    dp[i][limit] = valueSum 의 형태로 저장한다.
    이중 for 문을 수행하며, 이전 모든 dp 값에 현재 물건을 추가하여 최대가 되는 지를 체크한다.


    [ 자료형 ]
    N(1 ≤ N ≤ 100), K(1 ≤ K ≤ 100,000), W(1 ≤ W ≤ 100,000), V(0 ≤ V ≤ 1,000)
    최대값은 100 * 100,000 = 10,000,000 이므로 int를 사용한다

    [ 시간 복잡도 ]
    N 개수 만큼의 이중 for 문을 반복하므로, O(N^2) => O(100*100) 이다.

*/

pair<int, int> stuff[101];
int dp[101][100001];

int getMaxValue(int N, int K)
{
    for (int limit = 1; limit <= K; ++limit)
    {
        for (int i = 1; i <= N; ++i)
        {
            // 물건이 limit 보다 크다면, 담지 못하는 물건이므로 이전 i-1 까지의 dp 값을 가져온다
            if (stuff[i].first > limit)
                dp[i][limit] = dp[i - 1][limit];

            // i 번째 물건을 넣으려면, i-1 번째 까지의 물건을 넣었을 때, limit - stuff[i].first 일때에 i 를 넣었을 때가 최대일 것이다.
            // 만약, limit 이 10이고, 3번째 무게 5인 물건을 넣으려면, 2번째에 limit 5였던 상태의 가방에 3번째 물건을 넣는 것이 가장 큰 값을 가진다.
            // 그렇기에 이 값과, i 번째 물건을 넣지 않는 두 경우의 수를 비교해 최대값을 찾는다
            else
                dp[i][limit] = max(dp[i - 1][limit - stuff[i].first] + stuff[i].second, dp[i - 1][limit]);
        }
    }

    return dp[N][K];
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        int W, V;
        cin >> W >> V;
        stuff[i] = {W, V};
    }
    cout << getMaxValue(N, K);
}