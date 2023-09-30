#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/9251

    [ 문제 정리 ]
    LCS(Longest Common Subsequence, 최장 공통 부분 수열)
    두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는다.

    [ 해결 방법 ]
    두 문자열을 표의 가로와 세로로 생각한다.

    if (비교하는 위치의 문자가 서로 같으면)
        현재 위치의 값 = 대각선 위의 값 + 1
    else
        현재 위치의 값 = max(위쪽 값, 왼쪽 값)

    각 문자열을 A, B 라 두고, 각 문자열에 문자를 순서대로 1개씩 붙인다고 생각해보자.
    A :     B :      로 초기값은 비어 있을 것이고, 한 개씩 붙여 나간다.
    A : ac  B : c    상황에서 계속해서 문자를 순서대로 붙여 나갈 것이다.

    이때, 표에서 문자가 서로 같을 때는 양쪽 A, B에 같은 문자를 추가한다고 생각하면 된다.
    (4,3) 의 경우를 보면, 대각선 위의
    A : ac    B : c 의 양쪽에 a를 추가하여, 부분 수열이 c 에서
    A : aca   B : ca 로 부분 수열이 ca가 되었다. 길이가 1에서 2로 변화한 것이다.

    표에서 문자가 서로 다른 경우는 (5,3)을 보면
    A : aca   B : c 와 같은 경우로, 이전의 A 문자열에 서로 공통 부분이 없는 문자를 추가했으니
    공통 부분의 개수에 영향이 없다. 이는 A 또는 B 문자열 뒤에 문자 하나를 추가하는 것으로 볼 수 있으니,
    윗쪽 값(이전 B 문자열에 문자 추가) 과 왼쪽 값(이전 A 문자열에 문자 추가) 중 큰 값을 선택하면 된다.

      0 a c a y k p
    0 0 0 0 0 0 0 0
    c 0 0 1 1 1 1 1
    a 0 1 1 2 2 2 2
    p 0 1 1 2 2 2 3
    c 0 1 2 2 2 2 2
    a 0 1 2 3 3 3 3
    k 0 1 2 3 3 4 4

    최대값은 항상 마지막 원소가 된다. 따라서 마지막 원소를 출력한다.


    [ 자료형 ]
    문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
    최대 길이 또한 1000 이므로, int를 사용한다

    [ 시간 복잡도 ]
    O(가로 * 세로) 이므로, O(1000 * 1000) => O(1,000,000) 이다


*/

int dp[1001][1001];

int lengthLCS(string strA, string strB)
{
    int lenA = strA.length();
    int lenB = strB.length();
    for (int i = 0; i < lenA; ++i)
    {
        // dp[i][j] 에 값을 넣게 되면, dp[-1][-1]에 접근하게 되어,
        // 모든 index를 +1 해주었다
        for (int j = 0; j < lenB; ++j)
        {
            if (strA[i] == strB[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp[lenA][lenB];
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    ios::sync_with_stdio(0);

    string strA, strB;
    cin >> strA >> strB;

    cout << lengthLCS(strA, strB);
}