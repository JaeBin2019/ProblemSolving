#include <string>
#include <vector>
#include <set>

using namespace std;

/*

    https://school.programmers.co.kr/learn/courses/30/lessons/42895#

    [ 문제 정리 ]
    A 와 B 배열에 값이 주어지고, 두 배열에 있는 값을 최대 K회 변경할 수 있다.
    A 배열 전체 합이 최대가 되도록 하여라.

    N K
    A 배열
    B 배열

    5 3
    1 2 5 4 3
    5 5 6 6 5

    => 26

    [ 해결 방법 ]
    i = l + r
    dp[i].insert(dp[l] +-* dp[r])


    [ 자료형 ]
    1 <= N <= 100,000
    0 <= K <= N

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

void setInitVal(vector<set<int>> &dp, int N, int idx)
{
    int initVal = 0;
    for (int i = 0; i < idx; ++i)
    {
        initVal *= 10;
        initVal += N;
    }
    dp[idx].insert(initVal);
}

void setDpVal(vector<set<int>> &dp, int idx, int l, int r)
{
    for (int left : dp[l])
    {
        for (int right : dp[r])
        {
            dp[idx].insert(left + right);

            if (left > right)
                dp[idx].insert(left - right);

            dp[idx].insert(left * right);

            if (left >= right)
                dp[idx].insert(left / right);
        }
    }
}

int solution(int N, int number)
{
    int answer = 0;
    vector<set<int>> dp(9);

    for (int i = 1; i < 9; ++i)
    {
        setInitVal(dp, N, i);

        for (int l = 1; l < i; ++l)
        {
            int r = i - l;

            setDpVal(dp, i, l, r);
        }

        if (dp[i].find(number) != dp[i].end())
            return i;
    }

    return -1;
}