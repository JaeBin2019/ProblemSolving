#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*

    https://www.acmicpc.net/problem/2141

    [ 문제 정리 ]


    [ 해결 방법 ]


    [ 자료형 ]
    N : 마을 개수
    N <= 100,000

    X[i] : 마을 위치
    -1,000,000,000 <= X[i] <= 1,000,000,000

    A[i] : 사람 수
    1 <= A[i] <= 1,000,000,000

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/

#define x first
#define a second

pair<int, int> towns[100000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    long long sumVal = 0, cumSum = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> towns[i].x >> towns[i].a;
        sumVal += towns[i].a;
    }

    sort(towns, towns + n);

    for (int i = 0; i < n; ++i)
    {
        cumSum += towns[i].a;
        // 홀수 일 때, 절반 이상이 되도록 하기 위해서 +1 을 함
        if (cumSum >= (sumVal + 1) / 2)
        {
            cout << towns[i].x;
            return 0;
        }
    }
}