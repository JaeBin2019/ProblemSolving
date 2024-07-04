#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/11501

    [ 문제 정리 ]
    날 별로 주가를 예상하고 세 가지 중 한 행동을 한다.

    1. 주식 하나를 산다.
    2. 원하는 만큼 가지고 있는 주식을 판다.
    3. 아무것도 안한다.

    최대로 얻을 수 있는 이익을 구하여라

    [ 해결 방법 ]
    가장 많은 이익을 보기 위해서, 파는 날은 샀던 날보다 최대한 많은 차익이 나야한다
    때문에, 파는 날의 가격을 기준으로 사는 날보다 더 비싸면 무조건 그 주식을 사는 것이 이득이다.
    우리에게 자금의 한계는 없고, 아쉽게도 매일 살 수 있는 주식은 1주이기 때문에
    배열을 뒤에서부터 탐색하며, 가장 비싼 날을 찾으며


    [ 자료형 ]
    N : 날의 수
    1 <= N <= 1,000,000
    날별 주가 <= 10,000

    최대값 => 답은 부호있는 64bit 정수형으로 표현 가능

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
    차이값 계산 : N - 1 회
    1,000,000 - 1=> 0.01 * ~~~초


*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int caseCount;
    cin >> caseCount;

    for (int i = 0; i < caseCount; ++i)
    {
        vector<int> prices;
        long long result = 0;
        int priceCount, maxPrice;
        cin >> priceCount;

        for (int i = 0; i < priceCount; ++i)
        {
            int num;
            cin >> num;
            prices.push_back(num);
        }

        maxPrice = prices[prices.size() - 1];

        for (int i = prices.size() - 2; i >= 0; --i)
        {
            if (prices[i] < maxPrice)
                result += maxPrice - prices[i];

            if (prices[i] > maxPrice)
                maxPrice = prices[i];
        }

        cout << result << '\n';
    }
}