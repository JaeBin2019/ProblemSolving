#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/1904

    [ 문제 정리 ]
    00 타일과 1 타일로 n개에 해당하는 타일을 채울 때,
    나올 수 있는 모든 경우의 수 % 15746 을 구한다
    (1 <= n <= 1,000,000)

    [ 해결 방법 ]
    1. 이전 경우의 수에서 뒤에 1을 붙이거나, 00을 붙이는 2가지 경우의 수가 있다
    2. 00은 수가 2개가 붙기 때문에 전전 식의 경우의 수를, 1은 이전 식의 경우의 수를 가져온다

    d[i] = d[i-1] + d[i-2]
    d[1] = 1, d[2] = 2  라는 점화식이 유도된다

    [ 숫자 범위 ]
    '%' 연산을 하지 않을 시, 0과 1로 숫자를 만든다고 생각했을때, 
    2 ^ (1,000,000) 경우의 수가 생긴다. '% 15746' 조건을 통해,
    최대로 나올 수 있는 값은 15745 * 2 = 31490 인 것을 알 수 있다.
    따라서, int 자료형을 사용한다.

*/

int d[1000001];

int dp(int n)
{
    if (d[n])
        return d[n];
    
    d[n] = (dp(n - 1) + dp(n - 2)) % 15746;
    return d[n];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    d[1] = 1;
    d[2] = 2;

    int n;
    cin >> n;

    cout << dp(n);
}